#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

int a[200009], f[200009], g[200009];

int main() {
	FAST;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	f[1] = g[n] = 1;
	for(int i = 2; i <= n; i++) {
		if(a[i - 1] < a[i])
			f[i] = f[i - 1] + 1;
		else
			f[i] = 1;
	}
	for(int i = n - 1; i >= 1; i--) {
		if(a[i] < a[i + 1])
			g[i] = g[i + 1] + 1;
		else
			g[i] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	for(int i = 2; i < n; i++)
		if(a[i - 1] < a[i + 1])
			ans = max(ans, f[i - 1] + g[i + 1]);
	cout << ans << endl;
	return 0;
}