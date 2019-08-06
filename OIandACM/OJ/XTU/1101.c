#include <stdio.h>
#include <string.h>

inline char shui(char c){
	if('a' <= c && c <= 'z')
		return c + 'A' - 'a';
	else if('A' <= c && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

int main()
{
	int n, i;
	char s[2333];
	scanf("%d\n", &n);

	while(n--){
		gets(s);
		for(i = 0; i < strlen(s); i++)
			putchar(shui(s[i]));
		putchar('\n');
	}
	return 0;
}