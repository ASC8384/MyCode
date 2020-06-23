#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f[40009];

int main() {
	ll n;
	ll ans = 0;
	cin >> n;
	if(n == 1) {
		cout << 0 << endl;
		return 0;
	}

	n--;
	ans = n * n;
	for(int i = n; i >= 2; i--) {
		f[i] = (n / i) * (n / i);
		for(int j = 2 * i; j <= n; j += i) {
			f[i] -= f[j];
		}
		ans -= f[i];
	}
	cout << ans + 2 << endl;

	return 0;
}
/*
void phi_table(int n, int* phi) {
  for (int i = 2; i <= n; i++) phi[i] = 0;
  phi[1] = 1;
  for (int i = 2; i <= n; i++)
    if (!phi[i])
      for (int j = i; j <= n; j += i) {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
}
*/