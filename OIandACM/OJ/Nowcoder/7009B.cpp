/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-25 19:06:14
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

void prt(__int128 x) {
	if(x > 9)
		prt(x / 10);
	putchar(x % 10 + '0');
}

void read(__int128 &X) {
	X		= 0;
	int	 w	= 0;
	char ch = 0;
	while(!isdigit(ch)) {
		w |= ch == '-';
		ch = getchar();
	}
	while(isdigit(ch))
		X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	if(w)
		X = -X;
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int t = 1;
	// cin >> t;
	scanf("%d", &t);
	// ll n, m;
	while(t--) {
		// cin >> n >> m;
		// scanf("%lld%lld", &n, &m);
		__int128 n, m;
		read(n);
		read(m);

		__int128 ans = 1;
		__int128 i;
		bool	 ff = true;
		if(n >= m) {
			printf("0\n");
			continue;
		}

		for(i = 2; ff && i <= n; i++) {
			ans *= i;
			if(ans >= m) {
				ff = false;
				break;
			}
		}
		i = n + 1;
		n = ans;
		// ans = 1;
		for(; ff && i <= n; i++) {
			ans *= i;
			if(ans >= m) {
				ff = false;
				break;
			}
		}
		i = n + 1;
		n = ans;
		// ans = 1;
		__int128 zero = 0;
		if(ff)
			for(; i <= n; i++) {
				ans = ans * i % m;
				if(ans == zero) {
					break;
				}
			}
		if(ff)
			prt(ans);
		else
			printf("0");
		putchar('\n');
	}

	return 0;
}