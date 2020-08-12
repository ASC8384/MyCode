#include <bits/stdc++.h>
using namespace std;

#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(NULL);               \
	cout.tie(NULL)

// long long a[200008];
long long sum = 0;
long long a;
long long pl, pr;

const long long mod = 998244353;

int main() {
	FAST;
	long long pi = 0;
	// cout << 1 << endl;
	long long n, k;
	cin >> n >> k;
	long long ans = 1;
	for(long long i = 1; i <= n; i++) {
		// cin >> a[i];
		cin >> a;
		// if(a[i])
		if(a >= n - k + 1) {
			sum += a;
			if(pi == 0) {
				pi = i;
			} else {
				ans = ans * (i - pi) % mod;
				pi	= i;
			}
		}
	}
	cout << sum << " " << ans << endl;
	return 0;
}