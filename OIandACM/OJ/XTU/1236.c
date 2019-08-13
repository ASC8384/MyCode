#include <stdio.h>
#include <ctype.h>

int quick(int x, int n){
	int ret = 1;
	while(n){
		if(n & 1)
			ret = ret * x;
		x *= x;
		n >>= 1;
	}
	return ret;
}

inline unsigned long long init(void){
	unsigned long long x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

unsigned long long f[99];
unsigned long long s[99];

int main()
{
	int k = init();
	f[0] = 1;
	f[1] = 2;
	s[0] = 1;
	unsigned long long ans, n;
	// for(int i = 3; f[i - 1] <= 2e9; i++)
	for(int i = 2; i <= 45; i++)
		f[i] = f[i - 1] + f[i - 2];
	// for(int i = 1; s[i - 1] <= 2e9; i++)
	for(int i = 1; i <= 45; i++)
		s[i] = s[i - 1] << 1;

	while(k--){
		n = init();
		ans = 0;
		for(int i = 45; n > 0; i--)
			while(n >= f[i]){
				n -= f[i];
				ans += s[i];
			}
		printf("%I64d\n", ans);
	}
	return 0;
}