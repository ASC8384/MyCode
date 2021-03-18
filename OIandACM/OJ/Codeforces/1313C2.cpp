/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-02-18 22:29:23
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// const int size = 2e5 + 9;
#define size 500009

const ll mod = 1e9 + 7;

ll m[size], ans[size];
ll le[size], ri[size];

stack<int> s;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	// printf("1");

	int t = 1;
	// cout << 1;
	// cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> m[i];
		}
		// cout << 1;
		s.push(0);
		for(int i = 1; i <= n; i++) {
			while(!s.empty() && m[s.top()] > m[i]) {
				// le[s.top()] = i;
				s.pop();
			}
			// cout << s.top() << " ";
			le[i] = le[s.top()] + m[i] * (i - s.top());
			s.push(i);
		}
		// s.clear();
		while(!s.empty()) {
			s.pop();
		}
		s.push(n + 1);
		// cout << 1 << endl;
		for(int i = n; i; i--) {
			while(!s.empty() && m[s.top()] > m[i]) {
				// le[s.top()] = i;
				s.pop();
			}
			ri[i] = ri[s.top()] + m[i] * (s.top() - i);
			s.push(i);
		}
		ll now = 0, pos = 1;
		for(int i = 1; i <= n; i++) {
			if(le[i] + ri[i] - m[i] > now) {
				now = le[i] + ri[i] - m[i];
				pos = i;
			}
		}
		// cout << pos << endl;
		now = m[pos];
		for(int i = pos; i <= n; i++) {
			if(m[i] > now)
				m[i] = now;
			else
				now = m[i];
		}
		now = m[pos];
		for(int i = pos; i; i--) {
			if(m[i] > now)
				m[i] = now;
			else
				now = m[i];
		}
		for(int i = 1; i <= n; i++)
			cout << m[i] << ' ';
	}

	return 0;
}