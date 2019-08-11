#include <stdio.h>
#include <string.h>

int main()
{
	char s[233], t;
	int k, n, ll, i;
	scanf("%d", &n);

	while(n--){
		scanf("%s", s);
		scanf("%d%d", &k, &ll);
		for(i = 0; i < (ll >> 1); i++){
			t = s[i + k - 1];
			s[i + k - 1] = s[k + ll - 2 - i];
			s[k + ll - 2 - i] = t;
		}
		for(i = 0; i < strlen(s); i++)
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}