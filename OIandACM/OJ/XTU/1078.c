#include <stdio.h>

int main()
{
	char c;
	int i, j;
	int ans = 0;

	while((c = getchar()) != '#'){
		printf("case %d:\n", ++ans);
		for(i = 0; i < c - 'A' + 1; i++){
			for(j = i; j > 0; j--)
				putchar(' ');
			for(j = 'A'; j <= c - i; j++)
				putchar(j);
			for(j = c - i - 1; j >= 'A'; j--)
				putchar(j);
			putchar('\n');
		}
		getchar();
	}
	return 0;
}