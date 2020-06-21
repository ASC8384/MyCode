#include <bits/stdc++.h>
using namespace std;

const int size = 100000 + 90;

int a[size], q[size], top;
int f[size];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		int pos = lower_bound(q + 1, q + top + 1, a[i]) - q;
		while(q[pos + 1] == a[i] && pos < top)
			pos++;//nb
		if(pos > top || q[pos] != a[i]) {
			f[++top] = 1;
			q[top]	 = a[i] + 1;
		} else {
			f[pos]++;
			q[pos]++;
		}
	}
	int ans = f[1];
	for(int i = 2; i <= top; i++)
		ans = min(ans, f[i]);
	cout << ans << endl;

	return 0;
}