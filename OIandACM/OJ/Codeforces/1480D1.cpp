/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-02-07 23:43:25
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int n;
int a[size];

stack<int>	a1, a0;
vector<int> v;

void init(int n) {
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	v.push_back(a[1]);
	if(n != 1)
		v.push_back(a[2]);
	for(int i = 3; i <= n; i++) {
		if(a[i] == a[i - 1] && a[i - 1] == a[i - 2])
			continue;
		v.push_back(a[i]);
	}
}

int calc(int ans) {
	int now;
	int cnt;
	now = cnt = 0;
	int len	  = v.size();
	for(int i = 1; i < len; i++) {
		if(v[i] != v[i - 1]) {
			cnt++;
			if(v[i] == v[i - 2] && now == v[i])
				if(cnt == 2) {
					now = v[i];
					cnt = 0;
				}
			if(cnt >= 2)
				now = 0;
		} else {
			if(v[i] != now) {
				now = v[i];
				cnt = 0;
			} else {
				ans--;
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--) {
		cin >> n;
		init(n);
		int ans = v.size();

		a1.push(a[1]);
		a0.push(a[2]);
		for(int i = 3; i <= n; i++) {
			if(a[i] == a[i + 1]) {
				if(a1.top() != a[i])
					a1.push(a[i]);
				if(a0.top() != a[i])
					a0.push(a[i]);
				i += 2;
			} else {
				;
			}
		}
		int ans1 = 0;
		int ans0 = 0;
		while(!a1.empty()) {
			int x = a1.top();
			ans1++;
			a1.pop();
		}
		while(!a0.empty()) {
			int x = a0.top();
			ans0++;
			a0.pop();
		}
		cout << calc(ans) << '\n';
	}

	return 0;
}
