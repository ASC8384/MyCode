#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int ans = 0;
		int aa[23];
		memset(aa, 0, sizeof(aa));
		for(int i = 9; i; i--) {
			aa[i * k % 10] = i;
		}
		while(n >= k) {
			if(n % 10 == 0) {
				ans++;
				while(n % 10 == 0) {
					n /= 10;
					// ans++;
				}
			}
            if(n < k)
                break;
			if(aa[n % 10] != 0 && aa[n % 10] <= n / k) {
				ans += aa[n % 10];
				n -= aa[n % 10] * k;
			} else {
				ans += n / k;
                n %= k;
			}
		}
		cout << ans << ' ' << n << '\n';
	}

	return 0;
}