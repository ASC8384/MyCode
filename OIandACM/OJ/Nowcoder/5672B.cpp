/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-01 13:57:13
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		if(n < m) // n > m
			swap(n, m);
		// int ans = 0;
		vector<int> a;
		while(n != m) {
			for(int i = 1; i <= m; i++)
				// cout << m << " ";
				a.push_back(m);
			n = n - m;
			if(n < m) // n > m
				swap(n, m);
		}
		for(int i = 1; i <= m; i++)
			// cout << m << " ";
			a.push_back(m);
		cout << a.size() << '\n';
		for(int i = 0; i < a.size(); i++)
			cout << a[i] << ' ';
		cout << '\n';
	}

	return 0;
}