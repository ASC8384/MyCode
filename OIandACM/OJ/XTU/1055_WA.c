#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, a, t;
	char s[999];
	scanf("%s", s);

	while(s[0] != '0'){
		n = 0;
		for(i = 0; i < strlen(s); i++)
			n += s[i] - '0';
		while(n > 10){
			t = n;
			a = 0;
			while(t){
				a += t % 10;
				t /= 10;
			}
			n = a;
		}
		printf("%d\n", n);
		scanf("%s", s);
	}
	return 0;
}