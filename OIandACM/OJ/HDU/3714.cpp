/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-17 16:23:17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e4 + 9;
const ll  mod  = 1e9 + 7;

int a[size], b[size], c[size];
int n;

double calc(double x) {
	double ret = a[1] * x * x + b[1] * x + c[1];
	for(int i = 2; i <= n; i++) {
		ret = max(ret, a[i] * x * x + b[i] * x + c[i]);
	}
	return ret;
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int t = 1;
	// cin >> t;
	scanf("%d", &t);
	while(t--) {
		// cin >> n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			// cin >> a[i] >> b[i] >> c[i];
			scanf("%d%d%d", a + i, b + i, c + i);
		double le = 0, ri = 1000;
		while(ri - le > 1e-11) {
			double mid	= (le + ri) / 2;
			double mmid = (mid + ri) / 2;
			if(calc(mid) < calc(mmid))
				ri = mmid;
			else
				le = mid;
		}
		printf("%.4f\n", calc(le));
	}

	return 0;
}