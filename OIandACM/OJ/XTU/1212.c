#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	while(n){
		for(int i = 1; i < n; i++)
			putchar(' ');
		putchar('1');
		putchar('\n');
		for(int i = 1; i < n; i++){
			for(int j = 1; j < n - i; j++)
				putchar(' ');
			for(int j = 1; j <= i; j++)
				putchar(j + '0');
			putchar('+');
			for(int j = i; j >= 1; j--)
				putchar(j + '0');
			putchar('\n');
		}
		scanf("%d", &n);
	}
	return 0;
}