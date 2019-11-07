#include <cstdio>
#include <cstring>

const int n = 1e5+9;
int f[n];
bool flag = true;

int find(int x){
	while(x != f[x])
		x = f[x];
	return x;
}

int main()
{
	int k = 0;
	int x, y;
	while(scanf("%d%d", &x, &y) == 2){
		if(x == 0 && y == 0){
			int cnt = 0;
			for(int i = 1; i < n; i++){
				if(f[i] == i)
					cnt++;
				f[i] = 0;
			}
			if(flag && cnt == 1)
				printf("Case %d is a tree.\n", ++k);
			else
				printf("Case %d is not a tree.\n", ++k);
			//for(int i = 1; i < 23; i++) printf("%d:%d\n", i, find(i));
			// printf("%d\n", cnt);
			// memset(f, 0, sizeof(f));
			flag = true;
		}else if(x == -1 && y == -1){
			break;
		}else{
			if(f[x] == 0)
				f[x] = x;
			if(f[y] == 0)
				f[y] = y;
			if(find(x) == find(y) && flag)
				flag = false;
			else
				f[find(y)] = find(x);
		}
	}
	return 0;
}