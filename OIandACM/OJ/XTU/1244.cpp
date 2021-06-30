#include <bits/stdc++.h>
using namespace std;

int a[10009];
int n, m, sum, fir;

bool is(int x) {
	int cnt, day = 0;
	for(int i = 1; i <= n;) {
		day++;
		cnt = a[i++];
		while(cnt + a[i] <= x && i <= n)
			cnt += a[i++];
	}
	return day <= m;
}

int er() {
	int ans, ll, rr;
	// ll = 1;
	ll = fir;
	rr = sum;
	while(ll <= rr) {
		int mid = (ll + rr) / 2;
		if(is(mid)) {
			ans = mid;
			rr	= mid - 1;
		} else
			ll = mid + 1;
	}
	return ans;
}

int main() {
	int T;
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--) {
		sum = 0;
		cin >> n >> m;
		fir = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
			fir = max(fir, a[i]);
		}
		cout << er() << '\n';
	}
	return 0;
}
