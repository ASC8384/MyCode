#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct point {
	double x, y;
} p[33];
int n;

double mid1, mid2;

double calc(double x) {
	double minx, miny, maxx, maxy;
	double tmpx, tmpy;
	minx = miny = 1e9;
	maxx = maxy = -1e9;
	for(int i = 1; i <= n; i++) {
		tmpx = p[i].x * cos(x) - p[i].y * sin(x);
		tmpy = p[i].y * cos(x) + p[i].x * sin(x);
		minx = min(tmpx, minx);
		miny = min(tmpy, miny);
		maxx = max(tmpx, maxx);
		maxy = max(tmpy, maxy);
	}
	return max(maxx - minx, maxy - miny);
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		for(int i = 1; i <= n; i++)
			printf("%lf %lf\n", p[i].x, p[i].y);

		double ll = 0;
		double ri = acos(-1.0);
		while(ri - ll > 1e-8) {
			mid1 = (ll * 2 + ri) / 3;
			mid2 = (ll + ri * 2) / 3;
			if(calc(mid1) < calc(mid2))
				ri = mid2;
			else
				ll = mid1;
		}
		ll = calc(ll);
		printf("%.2lf\n", ll * ll);
	}
	return 0;
}

/*
逆时针
x1=xcos(β)-ysin(β);
y1=ycos(β)+xsin(β);

顺时针
x1=xcos(β)+ysin(β);
y1=ycos(β)-xsin(β);
*/
// 那么问题来了，为啥是