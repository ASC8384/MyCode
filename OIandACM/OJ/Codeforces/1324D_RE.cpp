#include <bits/stdc++.h>
using namespace std;

int a[20009];
int b[20009];
// string s;

// inline int init()

int main() {
	// int tim = clock();
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int j = 1; j <= n; j++) {
		cin >> b[j];
		a[j] -= b[j];
	}
	unsigned int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < i; j++) {
			if(a[i] + a[j] > 0)
				ans++;
		}
	}
	// printf()
	cout << ans << endl;
	// cout << clock() - tim << endl;

	return 0;
}