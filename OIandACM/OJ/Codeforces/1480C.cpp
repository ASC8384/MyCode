#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
int		  tmp  = 1e9 + 7;

void calc(int n) {
	// cin >> n;
	int le;
	int ri;
	le = 1;
	ri = n;
	while(true) {
		int x;
		int ans = (le + ri) / 2;
		if(ans == 1)
			x = tmp;
		else {
			cout << "? " << ans - 1 << endl;
			cin >> x;
			cout.flush();
		}
		cout << "? " << ans << endl;
		int now, kk;
		cin >> now;
		cout.flush();
		if(ans != n) {
			cout << "? " << ans + 1 << endl;
			cin >> kk;
			cout.flush();
		} else {
			kk = tmp;
		}
		if(now < x && now < kk) {
			cout << "! " << ans << endl;
			cout.flush();
			break;
		} else {
			if(x <= kk) {
				le = ans;
			} else {
				ri = ans;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--) {
		int n, le, ri;
		cin >> n;
		calc(n);
	}

	return 0;
}