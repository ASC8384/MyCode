#include <stdio.h>

int main()
{
	char c;
	int i, j;

	while((c = getchar()) != '#'){
		for(i = 0; i < c - 'A' + 1; i++){
			for(j = i; j > 0; j--)
				putchar(' ');
			for(j = 'A'; j <= c - i; j++)
				putchar(j);
			for(j = c - i - 1; j >= 'A'; j--)
				putchar(j);
			putchar('\n');
		}
	}
	return 0;
}