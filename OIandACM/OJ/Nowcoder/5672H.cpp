#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
long long mod = 1e9 + 7;

int main() {
	double	  Ol = 0.57721566490153286060651209;
	long long n, k;
	while(scanf("%lld%lld", &n, &k)) {
		if(n == 1) {
			k = k % mod;
			printf("%lld\n", k);
			return 0;
		}
		// if(k < 1e7) {
		// 	long long a	  = 0;
		// 	long long ans = n;
		// 	for(long long i = 2; i <= k; i++)
		// 		ans = (ans + n / i * 2) % mod;
		// 	printf("%lld\n", ans);
		// 	long long tmp = ans;
		// 	for(long long i = 2; i <= k; i++)
		// 		ans = (ans + (n % i > 0)) % mod;
		// 	printf("%lld\n", tmp - ans);
		// 	// return 0;
		// 	continue;
		// }
		long long ans = n % mod;
		long long nn  = n;
		// for(long long le = 1, ri; le <= k && nn / le != 0; le = ri + 1) {
		for(long long le = 2, ri; le <= min(k, n); le = ri + 1) {
			ri	= nn / (nn / le);
			ans = ((ri - le + 1) * (nn / le) * 2ll + ans) % mod;
		}
		// ans = (2 * ans + mod + n % mod) % mod;
		cout << ans << endl;
		// long long tmp = ans;
		nn = k;
		for(long long i = 1; i * i <= n && i <= nn; i++)
			if(n % i == 0) {
				k--;
				if(i * i != n && n / i <= nn)
					k--;
			}
		ans = (ans + k) % mod;
		printf("%lld\n", ans);
	}
}
