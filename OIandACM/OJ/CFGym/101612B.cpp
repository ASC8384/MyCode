#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char s[9876];

ll qpow(ll t) {
	ll ret = 1;
	ll n   = 2;
	while(t) {
		if(t & 1)
			ret *= n;
		n *= n;
		t >>= 1;
	}
	return ret;
}

bool f1[500], f2[666];
bool f[567];

int main() {
	freopen("boolean.in", "r", stdin);
	freopen("boolean.out", "w", stdout);

	scanf("%s", s);
	ll len = strlen(s);
	ll ans = 1;

	ll n = 0;
	ll m = 0;

	memset(f1, 0, sizeof(f1));
	memset(f2, 0, sizeof(f2));
	memset(f, 0, sizeof(f));
	bool flag = false;
	for(int i = 0; i < len; i++) {
		if(s[i] == '|') {
			;
		} else if(s[i] == '~') {
			if(!f2[s[i + 1]]) {
				f2[s[i + 1]] = 1;
				if(f1[s[i + 1]]) {
					flag = true;
					// n--;
					// m++;
				} else {
					// n++;
				}
			}
			i++;
		} else {
			if(!f1[s[i]]) {
				f1[s[i]] = 1;
				if(f2[s[i]]) {
					flag = true;
					// n--;
					// m++;
				} else {
					// n++;
				}
			}
		}
	}
	for(int i = 0; i < len; i++) {
		if(isalpha(s[i]))
			if(!f[s[i]]) {
				m++;
				f[s[i]] = 1;
			}
	}
	if(flag)
		printf("%lld\n", (qpow(m)));
	else
		printf("%lld\n", qpow(m) - 1);

	return 0;
}