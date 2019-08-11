#include <stdio.h>
#include <string.h>

inline int shu(char c){
	if('0' <= c && c <= '9')
		return c - '0';
	if('A' <= c && c <= 'Z')
		return c - 'A' + 10;
	if('a' <= c && c <= 'z')
		return c - 'a' + 36;
}

int main()
{
	int n;
	char s[66];
	__int64 ans, tmp, i, k;

	scanf("%d", &n);
	while(n--){
		scanf("%s%I64d", s, &k);
		tmp = 0;
		if(s[0] == '-'){
			for(i = 1; i < strlen(s); i++)
				tmp = tmp * k + shu(s[i]);
			ans = -1 * tmp;
		}
		else{
			for(i = 0; i < strlen(s); i++)
				tmp = tmp * k + shu(s[i]);
			ans = tmp;
		}

		scanf("%s%I64d", s, &k);
		tmp = 0;
		if(s[0] == '-'){
			for(i = 1; i < strlen(s); i++)
				tmp = tmp * k + shu(s[i]);
			tmp = -1 * tmp;
		}
		else{
			for(i = 0; i < strlen(s); i++)
				tmp = tmp * k + shu(s[i]);
		}
		printf("%I64d\n", ans + tmp);
	}
	return 0;
}