#include <bits/stdc++.h>
using namespace std;

long long a[500009];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	a[1]		= 0;
	a[3]		= 8;
	a[5]		= 40;
	long long k = 3;
	for(int i = 7; i <= 500009; i += 2) {
		//a[i] = a[i - 2] + 12 * (i - 1) + 8 * ((i - 1) / 2 - 4);
		a[i] = a[i - 2] + 1ll * (4 * i - 4) * k;
		k++;
	}

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << a[n] << endl;
	}
	return 0;
}