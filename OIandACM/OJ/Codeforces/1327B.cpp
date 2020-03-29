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

bool f[100009];
bool ff[100009];

int main() {
	int n, t;
	t = init();
	while(t--) {
		memset(f, 0, sizeof(f));
		memset(ff, 0, sizeof(ff));
		int tmp;
		int ans2;
		int ans1 = 0;

		n = init();
		for(int i = 1; i <= n; i++) {
			int	 k	  = init();
			bool flag = true;
			for(int j = 1; j <= k; j++) {
				tmp = init();
				if(flag)
					if(!f[tmp]) {
						f[tmp] = true;
						ff[i]  = true;
						flag   = false;
						ans1++;
						// break;
					}
			}
		}
		if(ans1 != n) {
			for(int i = 1; i <= n; i++)
				if(!ff[i]) {
					ans1 = i;
					break;
				}
			for(int i = 1; i <= n; i++)
				if(!f[i]) {
					ans2 = i;
					break;
				}
			cout << "IMPROVE" << endl;
			cout << ans1 << " " << ans2 << endl;
		} else {
			cout << "OPTIMAL" << endl;
		}
	}
	return 0;
}