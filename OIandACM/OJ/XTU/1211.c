#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char s[2333];
	int a, b, c, i;
	scanf("%d", &n);

	while(n--){
		scanf("%s", s);
		a = s[0] - '0';
		for(i = 1; i <= 2333; i++)
			if(s[i] == '+')
				break;
			else
				a = a * 10 + s[i] - '0';
		b = s[++i] - '0';
		for(i++; i <= 2333; i++)
			if(s[i] == '=')
				break;
			else
				b = b * 10 + s[i] - '0';
		c = s[++i] - '0';
		for(i++; i < strlen(s); i++)
			c = c * 10 + s[i] - '0';
		// printf("%d %d %d\n", a, b, c);
		if(a + b == c)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}