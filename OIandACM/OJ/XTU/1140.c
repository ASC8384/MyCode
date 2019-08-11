#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	unsigned long long k;
	long long ans;
	char s[2333];
	scanf("%d", &n);

	while(n--){
		scanf("%s", s);
		ans = 0;
		k = 1;
		if(s[strlen(s) - 1] == '-')
			ans = -1;
		else
			ans = s[strlen(s) - 1] - '0';
		for(int i = strlen(s) - 2; i >= 0; i--){
			k *= 3;
			if(s[i] == '-')
				ans -= k;
			else
				ans += k * (s[i] - '0');
		}
		printf("%I64d\n", ans);
	}
	return 0;
}