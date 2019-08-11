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
		int top = 0;
		int c[23] = {0};
		while(a){
			c[++top] = (a % 10 + b % 10) % 10;
			a /= 10;
			b /= 10;
		}
		int sum = 0;
		if(c[top] == '0')
			printf("0");
		else{
			for(; top; top--)
				sum = sum * 10 + c[top];
				// putchar(c[top]);
		}
		printf("%d\n", sum);
	}
	return 0;
}