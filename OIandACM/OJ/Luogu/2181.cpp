#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long n;
	while(scanf("%llu", &n) != EOF) {
		printf("%llu\n", (n) * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4);
	}
	return 0;
}