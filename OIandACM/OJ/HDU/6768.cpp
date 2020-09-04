/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-23 16:22:45
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1000000 + 9;
const ll  mod  = 19260817;

ll f[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	f[1]  = 1;
	f[2]  = 2;
	for(int i = 3; i <= 1000000; i++)
		f[i] = (f[i - 1] + f[i - 2]) % mod;

	ll ans1, ans2, ans3;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a;
		int tmp1, tmp2;
		ans1 = ans2 = ans3 = 0;
		for(int i = 1; i <= a; i++) {
			cin >> tmp1;
			ans1 = (ans1 + tmp1 * f[i]) % mod;
		}
		cin >> b;
		for(int i = 1; i <= b; i++) {
			cin >> tmp1;
			ans2 = (ans2 + tmp1 * f[i]) % mod;
		}
		cin >> c;
		for(int i = 1; i <= c; i++) {
			cin >> tmp1;
			ans3 = (ans3 + tmp1 * f[i]) % mod;
		}
		ans3	= (ans1 * ans2 - ans3) % mod;
		int pos = 1;
		for(pos; pos <= size; pos++)
			if(f[pos] >= ans3)
				break;
		cout << pos;
	}

	return 0;
}