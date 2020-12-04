/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-11-19 21:58:23
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int	 size = 2e5 + 9;
const ll	 mod  = 1e9 + 7;
const double eps  = 1e-8;

int	   n;
double d;
struct LL {
	double x, y;
} a[size];

bool cmp(LL a, LL b) {
	return a.y - b.y < eps;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> d;
	d *= d;
	for(int i = 1; i <= n; i++) {
		double x, y;
		cin >> x >> y;
		a[i].x = x - sqrt(d - y * y);
		a[i].y = x + sqrt(d - y * y);
	}
	sort(a + 1, a + n + 1, cmp);
	int	   ans = 1;
	double now = a[1].y;
	for(int i = 1; i <= n; i++) {
		if(now - a[i].x < eps) {
			ans++;
			now = a[i].y;
		}
	}
	cout << ans;

	return 0;
}