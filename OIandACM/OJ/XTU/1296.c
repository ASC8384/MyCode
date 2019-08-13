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

int main()
{
	int k = init();
	int a, b;

	while(k--){
		a = init() - 1;
		b = init();
		printf("%d\n", (b - (b/2 + b/3 - b/6)) - (a - (a/2 + a/3 - a/6)));
	}
	return 0;
}