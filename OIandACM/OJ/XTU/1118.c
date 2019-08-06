#include <stdio.h>

int main()
{
	int a, b, c;
	//scanf("%d%d%d", &a, &b, &c);
	int n;
	scanf("%d", &n);
	while(n--){
	//while(a != 0 && b != 0 & c != 0){
		scanf("%d%d%d", &a, &b, &c);
		if(a)
			if(b*b - 4*a*c > 0)
				printf("2\n");
			else if(b*b - 4*a*c == 0)
				printf("1\n");
			else
				printf("0\n");
		else
			if(b)
				if(c)
					printf("1\n");
				else
					printf("INF");
			else if(c)
					printf("0\n");
				else
					printf("INF\n");
	}
	return 0;
}