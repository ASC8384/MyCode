#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct L {
	long long a, b;
} A[210000];
bool comp(L x, L y) {
	return x.a < y.a || (x.a == y.a && x.b < y.b);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &A[i].a);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &A[i].b);
		sort(A + 1, A + 1 + n, comp);
		long long k = 1, ans = 0;
		for(int i = 1; i <= n; i++) {
			if(k - A[i].a < 0)
				k = A[i].a;
			ans = max(ans, k - A[i].a);
			k += A[i].b;
		}
		printf("%lld\n", ans);
	}
}
