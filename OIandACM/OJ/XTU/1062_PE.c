#include <stdio.h>
#include <string.h>

int main()
{
	char c = getchar();
	if(c <= 'Z')
		printf("%c\n", c + 'a' - 'A');
	else
		printf("%c\n", c + 'A' - 'a');
	return 0;
}