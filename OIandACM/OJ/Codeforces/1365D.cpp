#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const int				   size = 105;
inline void				   qread() {}
template <class T1, class... T2>
inline void qread(T1 &IEE, T2 &... ls) {
	register T1	  __ = 0, ___ = 1;
	register char ch;
	while(!isdigit(ch = getchar()))
		___ = (ch == '-') ? -___ : ___;
	do {
		__ = (__ << 1) + (__ << 3) + (ch ^ 48);
	} while(isdigit(ch = getchar()));
	__ *= ___;
	IEE = __;
	qread(ls...);
	return;
}

int	 n, m;
int	 topg, topb, top;
char a[size][size];
bool v[size][size];
int	 gg[2666][2];
int	 bb[2666][2];

int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};

void bfs(int x, int y) {
	v[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int tmx = xx[i] + x;
		int tmy = yy[i] + y;
		if(v[tmx][tmy] || tmx < 1 || tmy < 1 || tmx > n || tmy > m || a[tmx][tmy] == 0)
			continue;
		bfs(tmx, tmy);
	}
}

char c[size][size];

int main() {
	int t;
	qread(t);
	while(t--) {
		qread(n, m);
		topg = topb = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				// char c = getchar();
				cin >> c[i][j];
				switch(c[i][j]) {
				case '.':
					a[i][j] = 1;
					break;
				case '#':
					a[i][j] = 0;
					break;
				case 'G':
					gg[++topg][0] = i;
					gg[topg][1]	  = j;
					a[i][j]		  = 2;
					break;
				case 'B':
					bb[++topb][0] = i;
					bb[topb][1]	  = j;
					a[i][j]		  = 3;
					break;
				}
			}
			// getchar();
		}
		if(topg == 0) {
			cout << "Yes" << endl;
			continue;
		}
		int flag = 0;
		for(int i = 1; i <= topb; i++) {
			for(int j = 0; j < 4; j++) {
				int tmx = bb[i][0] + xx[j];
				int tmy = bb[i][1] + yy[j];
				if(tmx < 1 || tmy < 1 || tmx > n || tmy > m)
					continue;
				if(a[tmx][tmy] == 2) {
					flag = 2;
					break;
				}
				if(a[tmx][tmy] == 3) {
					// a[tmx][tmy] = 0;
					continue;
				}
				a[tmx][tmy] = 0;
			}
			if(flag == 2)
				break;
		}
		if(flag == 2 || a[n][m] == 0) {
			cout << "No" << endl;
		} else {
			memset(v, 0, sizeof(v));
			bfs(n, m);
			flag = 1;
			for(int i = 1; i <= topg; i++)
				if(!v[gg[i][0]][gg[i][1]]) {
					flag = 0;
					break;
				}
			if(flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}