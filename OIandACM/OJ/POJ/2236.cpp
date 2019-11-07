#include <cstdio>
using namespace std;

int n, d;
int f[1002];
char s[22];
struct point{
	int x, y;
}pot[1002];
int ok[1002], top;

int find(int x){
	if(x == f[x])
		return x;
	else
		return f[x] = find(f[x]);
}

bool dis(point a, point b){
	if((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) <= d * d)
		return true;
	else
		return false;
}

int main()
{
	scanf("%d%d", &n, &d);
	for(int i = 1; i <=	n; i++)
		f[i] = i;
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &pot[i].x, &pot[i].y);
	while(~scanf("%s", s)){
		if(s[0] == 'O'){
			int tmp;
			scanf("%d", &tmp);
			for(int i = 1; i <= top; i++)
				if(dis(pot[tmp], pot[ok[i]]))
					f[find(tmp)] = find(f[ok[i]]);
			ok[++top] = tmp;
		}else if(s[0] == 'S'){
			int x, y;
			scanf("%d%d", &x, &y);
			if(find(x) == find(y))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
}