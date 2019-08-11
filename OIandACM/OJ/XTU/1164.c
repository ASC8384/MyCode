#include <stdio.h>
#include <string.h>

int main()
{
	char s[233];
	int i;
	int a[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

	while(~scanf("%s", s)){
		int ans = 0;
		for(i = 0; i < strlen(s); i++)
			ans += a[s[i] - '0'];
		printf("%d\n", ans);
	}
	return 0;
}