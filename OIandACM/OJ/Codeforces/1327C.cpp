#include <bits/stdc++.h>
using namespace std;

inline int init(void) {
	int	 x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar())
		;
	for(x = 0; isdigit(c); c = getchar())
		x = (x << 1) + (x << 3) + c - '0';
	return x;
}

int main() {
	int n, m, k;
	n = init();
	m = init();
	k = init();
	// if(m * n > m + n) {
	// for(int i = 1; i <= k; i++)
	cout << n * m + n + m - 1 << endl;
	for(int i = 1; i <= m; i++)
		putchar('L');
	for(int i = 1; i <= n; i++)
		putchar('U');
	for(int i = 1; i <= n; i++) {
		if(i & 1) {
			for(int j = 1; j < m; j++)
				putchar('R');
		} else {
			for(int j = 1; j < m; j++)
				putchar('L');
		}
		if(i != n)
			putchar('D');
	}
	// }
	return 0;
}