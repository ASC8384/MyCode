#include <bits/stdc++.h>
using namespace std;

int func(int x, int y){
	int ans = 0;
	while(x != 0 || y != 0){
		if((x & 1) != (y & 1))
			++ans;
		x >>= 1;
		y >>= 1;
	}
	return ans;
}

int main()
{
	int t;
	int n, m;
	int a[233], b;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &m, &n);
		for(int i = 0; i < m; i++)
			scanf("%d", a + i);
		sort(a, a + m);
		for(int i = 0; i < n; i++){
			scanf("%d", &b);
			int minn = 1e8;
			int it = 0;
			for(int j = 0; j < m; j++){
				if(minn > func(a[j], b)){
					minn = func(a[j], b);
					it = j;
				}
			}
			printf("%d\n", a[it]);
		}
	}
	//system("pause");
	return 0;
}
