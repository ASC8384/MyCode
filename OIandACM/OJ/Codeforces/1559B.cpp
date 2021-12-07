#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

char is(char c) {
	if(c == 'R')
		return 'B';
	else
		return 'R';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int len = s.length();
		for(int i = 1; i < len; i++)
			if(s[i - 1] != '?' && s[i] == '?') {
				s[i] = is(s[i - 1]);
			}
		for(int i = len - 2; i >= 0; i--)
			if(s[i + 1] != '?' && s[i] == '?') {
				s[i] = is(s[i + 1]);
			}
		if(s[0] == '?')
			s[0] = 'B';
		for(int i = 1; i < len; i++)
			if(s[i - 1] != '?' && s[i] == '?') {
				s[i] = is(s[i - 1]);
			}
		for(int i = len - 2; i >= 0; i--)
			if(s[i + 1] != '?' && s[i] == '?') {
				s[i] = is(s[i + 1]);
			}
		cout << s << '\n';
	}
	return 0;
}