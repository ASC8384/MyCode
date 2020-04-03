#include <bits/stdc++.h>

int main() {
	int n, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		if(n == 1)
			printf("-1");
		else {
			putchar('2');
			for(int i = 2; i <= n; i++)
				putchar('3');
		}
		putchar('\n');
	}
	return 0;
}