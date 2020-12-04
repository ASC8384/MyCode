#include <bits/stdc++.h>
using namespace std;

int	   n;
double ans;
struct LL {
	double x, y;
} node[200005];

double dis(LL a, LL b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(LL a, LL b) {
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

void solve(int tmp) {
	double rnd = tmp * 3.1415926535 / 180.0;
	for(int i = 1; i <= n; i++) {
		double ox = node[i].x;
		double oy = node[i].y;
		double xx = ox * cos(rnd) - oy * sin(rnd);
		double yy = ox * sin(rnd) + oy * cos(rnd);
		node[i].x = xx;
		node[i].y = yy;
		//printf("%lf %lf\n", xx, yy);
	}
	sort(node + 1, node + 1 + n, cmp);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 5; j++) {
			if(i + j <= n) {
				ans = min(ans, dis(node[i], node[i + j]));
			}
		}
	}
}

int main() {
	srand(time(NULL));
	scanf("%d", &n);
	//cin >> n;
	for(int i = 1; i <= n; i++) {
		//cin >> node[i].x >> node[i].y;
		scanf("%lf%lf", &node[i].x, &node[i].y);
		//printf("%lf %lf\n", node[i].x, node[i].y);
	}
	ans = 1e15 + 9.0;
	solve(0);
	//printf("%.4lf\n", ans);
	solve(rand() % 360);
	//printf("%.4lf\n", ans);
	solve(rand() % 360);
	printf("%.4lf\n", ans);
	return 0;
}