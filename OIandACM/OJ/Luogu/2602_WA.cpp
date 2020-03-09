#include <bits/stdc++.h>
using namespace std;

int		  f[22];
int		  t[22] = {1};
long long cnta[22], cntb[22];

void calc(long long x, long long *cnt) {
	int num[20] = {0};
	// int rex[20];
	int len = 0;
	while(x) {
		num[++len] = x % 10;
		x /= 10;
		// rex[len] = x;
	}

	for(int i = len; i > 0; i--) {
		for(int j = 0; j < 10; j++)
			cnt[j] += f[i - 1] * num[i]; // pu
		for(int j = 0; j < num[i]; j++)
			cnt[j] += t[i - 1]; // 0
		// cnt[num[i]] += rex[len - i + 1] + 1;
		long long tmp = 0;
		for(int j = i - 1; j > 0; j--)
			tmp = tmp * 10 + num[j]; // remain x

		cnt[num[i]] += tmp + 1;
		cnt[0] -= t[i - 1];
	}
}

int main() {
	long long int a, b;
	cin >> a >> b;

	for(int i = 1; i <= 15; i++) {
		f[i] = f[i - 1] * 10 + t[i - 1];
		t[i] = 10 * t[i - 1];
	}
	calc(a - 1, cnta);
	calc(b, cntb);

	for(int i = 0; i < 10; i++)
		printf("%lld ", cntb[i] - cnta[i]);

	return 0;
}
/*
22 88
6 6 15 17 17 17 17 17 16 6
*/