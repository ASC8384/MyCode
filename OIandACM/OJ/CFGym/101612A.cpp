#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll n;
	freopen("auxiliary.in", "r", stdin);
	freopen("auxiliary.out", "w", stdout);
	while(scanf("%lld", &n) != EOF) {
		if(n <= 5) {
			switch(n) {
			case 2:
				printf("1\n");
				break;
			case 3:
				printf("7\n");
				break;
			case 4:
				printf("4\n");
				break;
			default:
				printf("8\n");
				break;
			}
		} else {
			if(n % 3 == 1)
				printf("%lld\n", (n / 3 - 1) * 7 + 4);
			else if(n % 3 == 2)
				printf("%lld\n", (n / 3 * 7 + 1));
			else
				printf("%lld\n", n / 3 * 7);
		}
	}

	return 0;
}