#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f[233][233], t[233], a[233];

int main() {
	int T;
	cin >> T;
	t[1] = 1;
	for(int i = 2; i <= 65; i++)
		t[i] = t[i - 1] * 2;
	while(T--) {
		memset(f, 0, sizeof(f));
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = n - 2; i >= 0; i--) {
			for(int j = 1; j<= n - i; j++) {
				int now	 = j + i;
				if(now + 1 <= n) {
					ll tmp = a[now + 1] * t[n - i - 1];
					if(tmp + f[j][now + 1] < f[j][now] || f[j][now] == 0)
						f[j][now] = tmp + f[j][now + 1];
				}
				if(j - 1 > 0) {
					ll tmp = a[j - 1] * t[n - i - 1];
					if(tmp + f[j - 1][now] < f[j][now] || f[j][now] == 0)
						f[j][now] = tmp + f[j - 1][now];
				}
			}
		}
		ll ans = 0x7fffffffffffffff;
		for(int i = 1; i <= n; i++) {
			f[i][i] += t[n] * a[i];
			ans = min(ans, f[i][i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
