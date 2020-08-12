#include <bits/stdc++.h>
using namespace std;

const long long size = 1e6 + 119;

bool	  a[size], b[size], f[size];
long long n;
long long t1[size], t2[size];
long long suma, sumb;
long long cnt1, cnt2;
long long now1, now2;

long long find(bool flag, long long now) {
	for(long long i = now; i <= n; i++)
		if(a[i] != flag && !f[i]) {
			f[i] = true;
			return i;
		}
	return 0;
}

long long is(bool flag, long long pos) {
	if(flag) {
		for(long long i = now2 + 1; i <= cnt2 && t2[i] >= pos; i++) {
			now2++;
			f[t2[now2]] = true;
			return t2[now2];
		}
		return false;
	} else {
		for(long long i = now1 + 1; i <= cnt1 && t1[i] >= pos; i++) {
			now1++;
			f[t1[now1]] = true;
			return t1[now1];
		}
		return false;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	// long long n;
	cin >> n;
	// char c;
	string s;
	cin >> s;
	for(long long i = 1; i <= n; i++) {
		// cin >> c;
		a[i] = s[i - 1] - '0';
		// cin >> a[i];
		suma += a[i];
	}
	cin >> s;
	for(long long i = 1; i <= n; i++) {
		// cin >> b[i];
		b[i] = s[i - 1] - '0';
		sumb += b[i];
	}
	if(suma != sumb) {
		cout << -1 << endl;
		return 0;
	}
	if(suma == 0 || sumb == n)
		cout << 0 << endl;
	else {
		int ans1 = 0, ans2 = 0;
		int tmp = 0;
		for(int i = 1; i <= n; i++) {
			tmp += a[i] - '0';
			tmp -= b[i] - '0';
			ans1 = max(tmp, ans1);
			ans2 = min(tmp, ans2);
		}
		cout << ans1 - ans2 << endl;
	}
	return 0;
}