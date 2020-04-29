/***
 * @Author       : ASC_8384
 * @License      : CC0
 * @Website      : http://www.ASC8384.top
 * @FilePath     : \OIandACM\OJ\Luogu\3406.cpp
 * @Date         : 2020-04-28 17:38:51
 * @LastEditTime : 2020-04-28 17:38:51
 * @Description  : P3406
 */

#include <bits/stdc++.h>
using namespace std;

unsigned long long n, m, p[100009], a[100009], b[100009], c[100009], t[100009], ans;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> p[i];
	}
	for(int i = 1; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	for(int i = 1; i < m; i++) {
		if(p[i] < p[i + 1]) {
			t[p[i]]++;
			t[p[i + 1]]--;
		} else {
			t[p[i]]--;
			t[p[i + 1]]++;
		}
	}
	for(int i = 1; i <= n; i++) {
		t[i] += t[i - 1];
	}
	for(int i = 1; i < n; i++) {
		ans += min(t[i] * a[i], t[i] * b[i] + c[i]);
	}
	cout << ans << endl;
	return 0;
}