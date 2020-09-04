#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int n, x, y;

void dayu() {
	cout << "NO" << '\n';
}

void dgyu(int x, int y, int n) {
	cout << "YES" << '\n';
	for(int i = 1; i < x; i++) {
		cout << i << ' ';
	}
	for(int i = 1, j = n; i <= y; i++, j--) {
		if(i != y)
			cout << j << ' ';
		else
			cout << j << '\n';
	}
}

int gc(int i) {
	cout << 1;
	for(int j = 2; j <= i; j++)
		cout << ' ' << j;
	for(int j = i + (n - i) % y; j >= i + 1; j--)
		cout << ' ' << j;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T = 1;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> n >> x >> y;
		if((x + y) > (n + 1)) {
			dayu();
		} else if((x + y) == (n + 1)) {
			dgyu(x, y, n);
		} else if((x + y) < (n + 1)) {
			int op = n / y;
			if(n % y)
				op++;
			if(op > x)
				cout << "NO" << '\n';
			else {
				cout << "YES" << '\n';
				for(int i = 1; i < x; i++) {
					int k = i;
					k += (n - i) / y;
					if((n - i) % y != 0)
						k++;
					if(k != x)
						continue;
					gc(i);
					int tmp = i + (n - i) % y + 1;
					while(true) {
						for(int j = tmp + y - 1; j >= tmp; j--)
							cout << ' ' << j;
						if((tmp + y - 1) != n)
							tmp += y;
						else
							break;
					}
					cout << '\n';
					break;
				}
			}
		}
	}
	// cin >> n >> x >> y;

	return 0;
}
