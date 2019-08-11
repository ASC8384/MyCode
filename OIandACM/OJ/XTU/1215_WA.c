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

	while(k--){
		int a = init();
		int b = init();
		if(a < b){
			int t = b;
			b = a;
			a = t;
		}
		int c = (a % 10 + b % 10) % 10;
		a /= 10;
		b /= 10;
		while(a){
			c = 10 * c + (a % 10 + b % 10) % 10;
			a /= 10;
			b /= 10;
		}
		printf("%d\n", c);
	}
	return 0;
}