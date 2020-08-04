/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-04 00:09:54
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;

const int size = 2e6 + 9;
const ll  mod  = 998244353;
const int base = 233;

string s[size];
int	   kmp[size];
int	   cnt[size];

map<ull, int> mp;

void getnext(string s) { // begin 0
	kmp[0] = 0;
	for(int i = 1, j = 0, n = (int)s.size(); i < n; i++) {
		while(s[i] != s[j] && j)
			j = kmp[j - 1];
		if(s[i] == s[j])
			j++;
		kmp[i] = j;
	}
}

void ha(string s) {
	ull hash = 0, now = 1;
	for(int i = s.length() - 1; i >= 0; i--, now *= base) {
		hash += now * (s[i] - 'a' + 1);
		mp[hash]++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> s[i];
		ha(s[i]);
	}
	ll ans = 0;
	for(int i = 1; i <= t; i++) {
		getnext(s[i]);
		ull hash = 0;
		int len	 = (int)s[i].length();
		for(int j = 0; j < len; j++) {
			hash	   = hash * base + s[i][j] - 'a' + 1;
			cnt[j + 1] = mp[hash];
			cnt[kmp[j]] -= cnt[j + 1];
		}
		for(int j = 1; j <= len; j++) {
			ans = (ans + 1ll * cnt[j] * j % mod * j % mod);
			if(ans >= mod)
				ans -= mod;
		} // ans = (ans + 1ll * cnt[j] * j % mod * j % mod) % mod;
	}
	cout << ans << '\n';

	return 0;
}