#include <stdio.h>
#include <string.h>

int main()
{
	char c = getchar();
	if(c <= 'Z')
		printf("%c", c + 'a' - 'A');
	else
		printf("%c", c + 'A' - 'a');
	return 0;
}