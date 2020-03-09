#include <bits/stdc++.h>
using namespace std;

unsigned long long f[22];
unsigned long long t[22] = {1};
unsigned long long cnta[22], cntb[22];

void calc(unsigned long long x, unsigned long long *cnt) {
	unsigned long long num[20] = {0};
	// int rex[20];
	unsigned long long len = 0;
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
		unsigned long long tmp = 0;
		for(int j = i - 1; j > 0; j--)
			tmp = tmp * 10 + num[j]; // remain x

		cnt[num[i]] += tmp + 1;
		cnt[0] -= t[i - 1];
	}
}

int main() {
	unsigned long long int a, b;
	cin >> b;
	a = 1;

	for(int i = 1; i <= 15; i++) {
		f[i] = f[i - 1] * 10 + t[i - 1];
		t[i] = 10 * t[i - 1];
	}
	calc(a - 1, cnta);
	calc(b, cntb);

	for(int i = 0; i < 10; i++)
		printf("%lld\n", cntb[i] - cnta[i]);

	return 0;
}