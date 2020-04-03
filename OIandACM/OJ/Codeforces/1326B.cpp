#include <bits/stdc++.h>

int main() {
	int n, t;
	scanf("%d", &t);
	int ans = 0;
	while(t--) {
		scanf("%d", &n);
		if(n >= 0)
			printf("%d ", ans += n);
		else
			printf("%d ", ans + n);
	}
	return 0;
}