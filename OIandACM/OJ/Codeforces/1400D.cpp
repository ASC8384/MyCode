#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 3000 + 9;
const int oh   = 3000;

int a[size];
ll	s[size][size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		memset(s, 0, sizeof(s));
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= oh; j++) {
				s[j][i] = s[j][i - 1];
				if(j == a[i])
					s[j][i]++;
			}
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				ans += (s[a[j]][i - 1]) * (s[a[i]][n] - s[a[i]][j]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}