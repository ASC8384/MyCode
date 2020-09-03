#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define inf 0x7fffffff
#define ll long long
#define maxn 300005

__int128 a[maxn], b[maxn];

void write(__int128 x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

__int128 read() {
	__int128 x = 0, f = 1;
	char	 ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x  = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main() {
	int i, j, k, t, n;
	scanf("%d", &t);
	int		 p	 = 0;
	// __int128 xxx = -12345678912345678912;
	// write(xxx);
	while(++p <= t) {
		scanf("%d", &n);
		a[0] = 0;
		// a[2] = 0;
		for(i = 1; i <= min(n, 2); i++) {
			a[i] = read();
			// scanf("%lld", &a[i]);
			//if(i>2) a[i]+=a[i-1];
		}
		__int128 cur = a[2];
		for(; i <= n; i++) {
			if(cur > 0)
				cur = 0;
			a[i] = read();
			// scanf("%lld\n", &a[i]);
			cur += a[i];
			a[i] = cur;
		}
		for(i = 1; i <= n; i++) {
			// scanf("%lld", &b[i]);
			b[i] = read();
			if(i > 1)
				// b[i] = min(b[i], b[i - 1]);
				if(b[i - 1] < b[i])
					b[i] = b[i - 1];
		}
		printf("Case #%d: ", p);
		write(b[1]);
		// printf("Case #%d: %lld ", p, b[1]);
		__int128 ans = b[1] * a[1];
		for(i = 2; i <= n; i++) {
			if(a[i] > 0)
				ans += a[i] * b[i];
		}
		// printf("%lld\n", ans);
		putchar(' ');
		write(ans);
		putchar('\n');
	}
}

/*
5
5 4 3 2 1
5 2 1 1 1*/
