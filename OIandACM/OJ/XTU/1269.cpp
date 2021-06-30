#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[2333], b[2333];

bool is(long long x) {
	long long now = k;
	for(long long i = 1; i <= n; i++) {
		if(x * a[i] > b[i]) {
			now -= (x * a[i] - b[i]);
			if(now < 0)
				return false;
		}
	}
	return true;
}

long long er() {
	long long le = 0, ri = 0x7fffffff;
	long long ret;
	while(le <= ri) {
		long long mid = (le + ri)/2;
		if(is(mid)) {
			ret = mid;
			le	= mid + 1;
		} else
			ri = mid - 1;
	}
	return ret;
}

int main() {
	int time;
	scanf("%d", &time);
	while(time--) {
		scanf("%lld%lld", &n, &k);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &b[i]);
		printf("%lld\n", er());
	}
	return 0;
}
