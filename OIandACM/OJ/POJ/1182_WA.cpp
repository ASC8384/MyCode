#include <cstdio>

int ans = 0;
int n, k;
int d, x, y;
int f[50002*3];

int find(int x){
	if(f[x] == x)
		return x;
	else
		return f[x] = find(f[x]);
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= 50001 * 3; i++)
		f[i] = i;
	//while(~scanf("%d%d%d", &d, &x, &y)){
	for(int i = 1; i <= k; i++){
		scanf("%d%d%d", &d, &x, &y);
		if(x > n || y > n){
			ans++;
			continue;
		}
		if(d == 1){
			if(find(x + n) == find(y) || find(y) == find(x + n + n))
				ans++;
			else{
				f[find(x)] = find(y);
				f[find(x + n)] = find(y + n);
				f[find(x + n + n)] = find(y + n + n);
			}
		}else if(d == 2){
			if(x == y || find(x) == find(y) || find(x + n + n) == find(y))
				ans++;
			else{
				f[find(x)] = find(y + n + n);
				f[find(x + n)] = find(y);
				f[find(x + n + n)] = find(y + n);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}