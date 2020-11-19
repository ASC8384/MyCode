#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-6;

struct LL {
	int x, y;
	LL	operator-(LL &a) {
		 return (LL){x - a.x, y - a.y};
	}
} a[55];

int operator*(LL a, LL b) {
	return a.x * b.y - b.x * a.y;
}

int is() {
	int ret = -1;
	for(int i = 1; i <= 3; i++) {
		if(a[i].x == a[4].x && a[i].y == a[4].y) {
			return 4;
		}
	}
	if((a[2] - a[1]) * (a[3] - a[1]) < 0)
		swap(a[2], a[3]);
	for(int i = 1; i <= 3; i++) {
		if((a[(i + 1) == 4 ? 1 : i + 1] - a[i]) * (a[4] - a[i]) == 0)
			return 3;
		if((a[(i + 1) == 4 ? 1 : i + 1] - a[i]) * (a[4] - a[i]) < 0)
			return 2;
	}
	return 1;
}

int main() {
	for(int i = 1; i <= 4; i++) {
		scanf("(%d,%d)\n", &a[i].x, &a[i].y);
	}
	printf("%d\n", is());
	return 0;
}