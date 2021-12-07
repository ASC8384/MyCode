#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;
bool	  isok;
string	  s;
ll		  len;

void c1() {
	for(ll i = 0; i < len; i++) {
		ll c = s[i] - '0';
		if(c % 2 == 0 && c != 2) {
			cout << 1 << '\n';
			cout << c << '\n';
			isok = true;
			return;
		}
		if(c == 1 || c == 9) {
			cout << 1 << '\n';
			cout << c << '\n';
			isok = true;
			return;
		}
	}
}

void c2() {
	for(ll i = len - 1; i >= 0; i--) {
		ll c = s[i] - '0';
		if(c == 2 && i != 0) {
			cout << 2 << '\n';
			cout << s[i - 1] << s[i] << '\n';
			isok = true;
			return;
		}
	}
}

void c3() {
	for(ll i = 0; i < len; i++) {
		ll c = s[i] - '0';
		if(c == 2) {
			ll flag = -1234;
			for(ll j = i + 1; j < len; j++) {
				if(s[j] == '5' || s[j] == '7') {
					flag = j;
					break;
				}
			}
			if(flag != -1234) {
				cout << 2 << '\n';
				cout << 2 << s[flag] << '\n';
				isok = true;
				return;
			}
		}
	}
}

void c4() {
	for(ll i = 0; i < len; i++) {
		ll c = s[i] - '0';
		if(c == 3) {
			ll flag = -1234;
			for(ll j = i + 1; j < len; j++) {
				if(s[j] == '5' || s[j] == '3') {
					flag = j;
					break;
				}
			}
			if(flag != -1234) {
				cout << 2 << '\n';
				cout << 3 << s[flag] << '\n';
				isok = true;
				return;
			}
		}
	}
}

void c5() {
	for(ll i = 0; i < len; i++) {
		ll c = s[i] - '0';
		if(c == 5) {
			ll flag = -1234;
			for(ll j = i + 1; j < len; j++) {
				if(s[j] == '5' || s[j] == '7') {
					flag = j;
					break;
				}
			}
			if(flag != -1234) {
				cout << 2 << '\n';
				cout << 5 << s[flag] << '\n';
				isok = true;
				return;
			}
		}
	}
}

void c6() {
	for(ll i = 0; i < len; i++) {
		ll c = s[i] - '0';
		if(c == 7) {
			ll flag = -1234;
			for(ll j = i + 1; j < len; j++) {
				if(s[j] == '5' || s[j] == '7') {
					flag = j;
					break;
				}
			}
			if(flag != -1234) {
				cout << 2 << '\n';
				cout << 7 << s[flag] << '\n';
				isok = true;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		ll k;
		cin >> k;
		cin >> s;
		len	 = s.size();
		isok = false;
		c1();
		if(isok)
			continue;
		c2();
		if(isok)
			continue;
		c3();
		if(isok)
			continue;
		c4();
		if(isok)
			continue;
		c5();
		if(isok)
			continue;
		c6();
	}

	return 0;
}