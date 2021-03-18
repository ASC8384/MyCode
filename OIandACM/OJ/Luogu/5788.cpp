/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-01-29 13:49:40
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 3e6 + 9;
const ll  mod  = 1e9 + 7;

int a[size], ans[size];

stack<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	s.push(n);
	ans[n] = 0;
	for(int i = n - 1; i; i--) {
		while(!s.empty()) {
			if(a[s.top()] <= a[i])
				s.pop();
			else
				break;
		}
		if(!s.empty())
			ans[i] = s.top();
		s.push(i);
	}
	cout << ans[1];
	for(int i = 2; i <= n; i++)
		cout << ' ' << ans[i];

	return 0;
}