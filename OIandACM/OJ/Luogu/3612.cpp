#include <bits/stdc++.h>

int main() {
	// string s;
	char s[100];
	scanf("%s", s);
	long long n;
	scanf("%lld", &n);
	long long len = strlen(s);
	while(len < n) {
		long long i = len;
		while(n > i * 2)
			i <<= 1;
		n -= (i + 1);
		if(n == 0)
			n = i;
	}
	printf("%c", s[n - 1]);
	return 0;
}