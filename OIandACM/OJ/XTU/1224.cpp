/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-10-03 11:12:15
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mod = 1000000007;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	char cc;
	scanf("%*d\n");
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	while(scanf("%c", &cc) != EOF) {
		if(cc == 'L')
			a++;
		else if(cc == 'O')
			b += a;
		else if(cc == 'V')
			c += b;
		else if(cc == 'E')
			d += c;
		else if(cc == '\n') {
			cout << d % mod << '\n';
			a = 0;
			b = 0;
			c = 0;
			d = 0;
		}
	}

	return 0;
}