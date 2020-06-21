#include <bits/stdc++.h>
using namespace std;

int main() {
	char   c, x;
	int	   now = 0;
	int	   a   = 0;
	int	   b   = 0;
	double ans = 0;
	bool   uu  = false;
	int	   f   = 1;
	int	   dg  = 1;

	while(cin >> c) {
		if(c == '-') {
			uu = false;
			a += now * f * dg;
			now = 0;
			f	= -1;
		}
		if(c == '+') {
			uu = false;
			a += now * f * dg;
			now = 0;
			f	= 1;
		}
		if(c == '=') {
			uu = false;
			a += now * f * dg;
			now = 0;
			f	= 1;
			dg	= -1;
		}
		if(isdigit(c)) {
			now = now * 10 + c - '0';
			uu	= true;
		}
		if('a' <= c && c <= 'z') {
			if(uu) {
				b += now * dg * f;
				now = 0;
			} else {
				b += 1 * dg * f;
			}
			x  = c;
			uu = false;
		}
	}
	a += now * dg * f;
	ans = 1.0 * a / (b * -1.0);
	if(ans == -0.0)
		ans = abs(ans);
	printf("%c=%.3lf", x, ans);
	// cout
	return 0;
}