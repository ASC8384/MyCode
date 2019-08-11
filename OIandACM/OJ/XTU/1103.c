#include <stdio.h>
#include <string.h>

int main()
{
	int n, i;
	char s[23];
	int ni, yu, ri;
	int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	scanf("%d", &n);
	while(n--){
		scanf("%s", s);
		ni = s[0] - '0';
		for(i = 1; i < 4; i++)
			ni = ni * 10 + s[i] - '0';
		yu = s[5] - '0';
		yu = yu * 10 + s[6] - '0';
		if(yu > 2){
			if((ni % 4 == 0 && ni % 100) ||
				(ni % 400 == 0 && ni % 3200))
				a[2] = 29;
			else
				a[2] = 28;
		}
		ri = s[8] - '0';
		ri = ri * 10 + s[9] - '0';
		for(i = 1; i < yu; i++)
			ri += a[i];
		printf("%d\n", ri);
	}
}