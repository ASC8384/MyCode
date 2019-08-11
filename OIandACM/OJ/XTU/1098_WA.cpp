// 仅做测试
#include <bits/stdc++.h>

const int MAXN = 1000009;// 6893911;
int p[MAXN], cnt;
bool mark[MAXN];
int pi[MAXN];

void init(){
	int i,j;
	for (i = 2; i < MAXN;i++){
		if (!mark[i])
			p[cnt++] = i;
		pi[i] = pi[i - 1] + !mark[i];
		for (j = 0; p[j] * i < MAXN && j < cnt; j++){
			mark[p[j] * i] = true;
			if (i%p[j] == 0)
				break;
		}
	}
}

int f(int n, int m){
	if (n == 0)
		return 0;
	if (m == 0)
		return n - n / 2;
	return f(n, m - 1) - f(n / p[m], m - 1);
}

int Pi(int n);

int p2(int n, int m){
	int ans = 0;
	for (int i = m + 1;(__int64)p[i]*p[i] <= n; i++)
		ans += Pi(n / p[i]) - Pi(p[i]) + 1;
	return ans;
}

int p3(int n, int m){
	int ans = 0;
	for (int i = m + 1; (__int64)p[i] * p[i] * p[i] <= n; i++)
		ans += p2(n / p[i], i - 1);
	return ans;
}

int Pi(int N){
	if (N < MAXN)
		return pi[N];
	int lim = f(N, 0.25)+1;
	int i;
	for (i = 0; p[i] <= lim; i++);
	int ans = i + f(N, i - 1) - 1 - p2(N, i - 1) - p3(N, i - 1);
	return ans;
}

inline int in(void){
	char c;
	int x;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main()
{
	int k = in();
	int a, b;
	init();
	while(k--){
		a = in();
		b = in();
		printf("%d\n", Pi(b) - Pi(a - 1));
	}
	return 0;
}