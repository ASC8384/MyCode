/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-06-26 22:07:10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll size = 10009;
const ll mod  = 1e9 + 7;

ll	sp[size];
ll	ss[size];
ll	mp[size];
ll	ms[size];
int top = 0;
int cnt = 0;
int pos = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n = 1;
	cin >> n;
	ll m1, m2;
	cin >> m1 >> m2;
	ll ans = mod;
	if(m1 == 1) {
		cout << 0 << endl;
		return 0;
	}

	for(ll i = 2; i * i <= m1; i++) {
		cnt = 0;
		while(m1 % i == 0) {
			m1 /= i;
			// mm[i]++;
			cnt++;
		}
		if(cnt) {
			mp[++top] = i;
			ms[top]	  = cnt * m2;
		}
	}
	if(m1 > 1) {
		mp[++top] = m1;
		ms[top]	  = m2;
	}
	// for(int i = 1; i <= top; i++)
	// 	cout << i << ":" << mp[i] << ' ' << ms[i] << endl;

	ll s;
	for(ll i = 1; i <= n; i++) {
		cin >> s;
		pos	   = 0;
		ll tmp = 0;
		ll now = 1;
		for(ll j = 2; j * j <= s; j++) {
			cnt = 0;
			while(s % j == 0) {
				s /= j;
				cnt++;
			}
			if(cnt) {
				sp[++pos] = j;
				ss[pos]	  = cnt;
			}
			if(mp[now] == sp[pos]) {
				ll tim = mod;
				if(ms[now] % ss[pos] == 0)
					tim = ms[now] / ss[pos];
				else
					tim = ms[now] / ss[pos] + 1;
				tmp = max(tmp, tim);
				now++;
			}
		}
		if(s > 1) {
			sp[++pos] = s;
			ss[pos]	  = 1;
		}
		if(mp[now] == sp[pos]) {
			ll tim = mod;
			if(ms[now] % ss[pos] == 0)
				tim = ms[now] / ss[pos];
			else
				tim = ms[now] / ss[pos] + 1;
			tmp = max(tmp, tim);
			now++;
		}
		if(top == now - 1) {
			ans = min(ans, tmp);
		}
	}
	if(ans == mod)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}