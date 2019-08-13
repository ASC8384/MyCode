#include <stdio.h>
#include <string.h>

int main()
{
	int k;
	char a[23], b[23];
	scanf("%d", &k);

	while(k--){
		scanf("%s%s", a, b);
		for(int i = 0; i < strlen(a) + strlen(b); i++){
			if(i & 1)
				putchar(b[strlen(b) - 1 - (i >> 1)]);
			else
				putchar(a[i >> 1]);
		}
		putchar('\n');
	}
	return 0;
}