/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-25 20:06:00
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

void prt(char c, int n) {
	for(int i = 1; i <= n; i++)
		cout << c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n = 1;
	cin >> n;
	cout << "I love U forever.\n";
	for(int i = 1; i <= n; i++) {
		prt(' ', n - i + 1);
		prt('*', n + 2 * i - 2);
		prt(' ', 2 * n + 1 - 2 * i);
		prt('*', n + 2 * i - 2);
		cout << '\n';
	}
	int tmp = 6 * n - 1;
	for(int i = 0; i < 3 * n; i++) {
		prt(' ', i);
		prt('*', tmp - i * 2);
		cout << '\n';
	}

	return 0;
}
