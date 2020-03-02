#include <cstdio>
using namespace std;

int a[100008];
int n, m;

bool is(int x) {
	int tot = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		if(sum + a[i] < x)
			sum += a[i];
		else
			sum = a[i], tot++;
	}
	return tot >= m;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		int ll = 0;
		int rr = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			rr += a[i];
		}
		while(ll < rr) {
			int mid = (rr + ll) / 2;
			if(is(mid)) {
				ll = mid + 1;
			} else {
				rr = mid - 1;
			}
		}
		printf("%d\n", ll);
	}
	return 0;
}