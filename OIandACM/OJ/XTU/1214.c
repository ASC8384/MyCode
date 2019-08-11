#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	long long a, b, c, i;
	char s[2333];
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
		if(a + b == c)
			printf("0\n");
		else{
			int f = 0;
			for(int i = 1; i <= 8; i++){
				a *= 10;
				if(a + b == c){
					f = i;
					break;
				}
			}
			if(f)
				printf("%d\n", f);
			else{
				a /= 1e8;
				for(int i = -1; i >= -8; i--){
					b *= 10;
					if(a + b == c){
						f = i;
						break;
					}
				}
				if(f)
					printf("%d\n", f);
			}
		}
	}
	return 0;
}