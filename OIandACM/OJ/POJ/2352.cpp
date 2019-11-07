#include <cstdio>

const int n = 15000*3;
int x, y;
int c[n];
int ans[n];

int lowbit(int x){
	return x&(-x);
}

void update(int i, int x){
	while(i <= n){
		c[i] += x;
		i += lowbit(i);
	}
}

int sum(int i){
	int ret = 0;
	while(i > 0){
		ret += c[i];
		i -= lowbit(i);
	}
	return ret;
}

int main()
{
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d%d", &x, &y);
		x++;
		ans[sum(x)]++;
		update(x, 1);
	}
	for(int i = 0; i < k; i++)
		printf("%d\n", ans[i]);
	return 0;
}