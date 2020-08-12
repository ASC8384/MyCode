#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int		  N = 1001;
struct node {
	int pos, x;
} ma[N], min[N];
int h1, t1, h2, t2;
int a[N][N], w[N][N], ww[N][N];

int lcm(int a, int b) { return a * b / __gcd(a, b); }

int main() {
	//freopen("square.in","r",stdin);
	//freopen("square.out","w",stdout);
	int aa, bb, n;
	scanf("%d%d%d", &aa, &bb, &n);
	for(int i = 1; i <= aa; i++)
		for(int j = 1; j <= bb; j++)
			// scanf("%d", &a[i][j]);
			a[i][j] = lcm(i, j);
	for(int j = 1; j <= aa; j++) {
		h1 = h2 = 1;
		t1 = t2 = 0;
		for(int i = 1; i <= bb; i++) {
			if(h1 <= t1 && ma[h1].pos < i - n + 1)
				h1++;

			while(h1 <= t1 && ma[t1].x < a[j][i])
				t1--;
			ma[++t1].pos = i;
			ma[t1].x	 = a[j][i];
			if(i - n + 1 > 0)
				w[j][i - n + 1] = ma[h1].x;
		}
	}
	for(int j = 1; j <= bb - n + 1; j++) {
		h1 = h2 = 1;
		t1 = t2 = 0;
		for(int i = 1; i <= aa; i++) {
			if(h1 <= t1 && ma[h1].pos < i - n + 1)
				h1++;

			while(h1 <= t1 && ma[t1].x < w[i][j])
				t1--;
			ma[++t1].pos = i;
			ma[t1].x	 = w[i][j];

			if(i - n + 1 > 0)
				w[i - n + 1][j] = ma[h1].x;
		}
	}
	// int ans = 0x7fffffff;
	int ans = 0;
	for(int i = 1; i <= aa - n + 1; i++)
		for(int j = 1; j <= bb - n + 1; j++)
			ans += w[i][j];
	printf("%d\n", ans);
}