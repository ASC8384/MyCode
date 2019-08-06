#include <bits/stdc++.h>

int main()
{
	int n;
	char c;
	scanf("%d\n", &n);

	while(n--){
		while(true){
			c = getchar();
			if(c == '\n'){
				putchar('\n');
				break;
			}
			if('A' <= c && c <= 'E')
				putchar(c + 'V' - 'A');
			else if('F' <= c && c <= 'Z')
				putchar(c + 'A' - 'F');
			else
				putchar(c);
		}
	}
	return 0;
}