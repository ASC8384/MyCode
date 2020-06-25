#include <bits/stdc++.h>
using namespace std;

int a;
int f[1000006];

int main() {
	int n;
	cin >> n;
	int maxx = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a;
		maxx  = max(maxx, a);
		int m = sqrt(a);
		for(int i = 1; i <= m; i++) {
			if(a % i == 0) {
				f[i]++;
				if(i * i != a) {
					f[a / i]++;
				}
			}
		}
	}
	int ans = maxx;
	for(int i = 1; i <= n; i++) {
		while(f[ans] < i)
			ans--;
		cout << ans << '\n';
	}
	return 0;
}