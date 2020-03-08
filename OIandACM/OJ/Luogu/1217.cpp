#include <bits/stdc++.h>
using namespace std;

const int size = 10000000;

bool isp[size];
int  pri[size];
int  pri_top;

void make_prime(int maxn) {
	memset(isp, true, sizeof(isp));
	isp[0] = isp[1] = false;
	for(int i = 2; i <= maxn; i++) {
		if(isp[i])
			pri[++pri_top] = i;
		for(int j = 1; j <= pri_top && i * pri[j] <= maxn; j++) {
			isp[i * pri[j]] = false;
			if(!(i % pri[j]))
				break;
		}
	}
}

bool is(int x) {
	char s[12];
	sprintf(s, "%d", x);
	int ll = strlen(s);
	for(int i = 0; i < ll / 2; i++)
		if(s[i] != s[ll - i - 1])
			return false;
	return true;
}

int main() {
	int a, b;
	cin >> a >> b;
	if(b > size)
		b = size;

	make_prime(size);
	for(int i = a; i <= b; i++) {
		if(isp[i] && is(i))
			cout << i << endl;
	}

	return 0;
}