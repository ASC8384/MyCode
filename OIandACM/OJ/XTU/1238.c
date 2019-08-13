#include <stdio.h>
#include <ctype.h>

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

const int mo = 1e9 + 7;
unsigned long long a[1000009];
int p[1000009];

int main()
{
	int k = init();
	p[0] = 1;
	for(int i = 1; i <= 1000000; i++)
		p[i] = (p[i - 1] << 1) % mo;
	a[0] = 0;
	a[1] = 0;
	a[2] = 1;
	a[3] = 3;
	for(int i = 4; i <= 1000000; i++)
		a[i] = (a[i - 1] + a[i - 2] + p[i - 2]) % mo;

	while(k--){
		// int n = init();
		printf("%I64d\n", a[init()]);
	}
	return 0;
}