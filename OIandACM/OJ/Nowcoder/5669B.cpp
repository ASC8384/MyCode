/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-20 12:11:56
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1e6 + 9;
const ll  mod  = 1e9 + 7;

int n, c;

ll pow_mod(ll a, ll b) { //a的b次方求余p
	ll ret = 1;
	while(b) {
		if(b & 1)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

bool prime[size];
int	 p[size], ans[size];
int	 tot = 0;

void init() {
	for(int i = 2; i < size; i++) {
		if(p[i] != 0)
			continue;
		for(int j = i; j < size; j += i) {
			if(p[j] == 0)
				p[j] = i;
		}
	}
	ans[2] = 1;
	for(int i = 3; i < size; i++)
		ans[i] = ans[i / p[i]] + 1;
}

int read() {
	int	 x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar())
		;
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int t = 1;
	// cin >> t;
	t = read();
	init();
	while(t--) {
		// cin >> n >> c;
		n = read();
		c = read();
		// int x = 0;
		// int m = sqrt(n);
		// int i = 2;
		// for(int i = 2; i < m; i++) {
		// 	if(prime[i]) {
		// 		if(n % i == 0) {
		// 			x++;
		// 			n /= i;
		// 			i--;
		// 		}
		// 	}
		// }
		// if(n != 1)
		// 	x++;
		// if(n > 1)
		// 	x++;
		// for(int i = 0; i < tot && n != 1; i++) {
		// 	if(n % p[i] == 0) {
		// 		x++;
		// 		n /= p[i];
		// 		i = -1;
		// 	}
		// }
		// cout << pow_mod(c, x) << '\n';
		printf("%lld\n", pow_mod(c, ans[n]));
	}

	return 0;
}