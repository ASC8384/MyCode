#include <stdio.h>

char merge() {
	;
	;
}

int main() {
	int n;
	int t, k;

	scanf("%d", &n);
	t = 0;
	k = 3;
	while(t <= n) {
		t = t * 2 + k; // 3 + k;
		k++;
	}
	k--;

	while(t > 0) {
		t = (t - k) / 2;
		if(n > t) {
			if(n <= t + k) {
				if(n == t + 1) // first
					putchar('m');
				else // later
					putchar('o');
				return 0;
			} else
				n -= t + k;
		}
		k--;
	}

	// printf("%c", merge());

	return 0;
}