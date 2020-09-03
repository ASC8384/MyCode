/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-13 13:03:41
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int a[size] = {0, 46, 35, 24, 13, 62, 51};

int b[size] = {0, 5, 4, 3, 2, 1, 6};

void dfs(int n) {
	if(n == 1) {
		cout << 4;
		return;
	}
	if(n == 2) {
		cout << "543215";
		return;
	}
	for(int i = 1; i <= 6; i++) {
		cout << b[i];
		for(int j = 1; j <= n - 2; j++) {
			cout << a[i];
		}
	}
	dfs(n - 2);
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
		dfs(n);
		cout << '\n';
	}

	return 0;
}
