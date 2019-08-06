#include <stdio.h>

int main()
{
	int n;
	int a, b, c;
	scanf("%d", &n);

	while(n--){
		scanf("%d%d%d", &a, &b, &c);
		if(c == 1)
			if(a == b)
				printf("0\n");
			else
				printf("None\n");
		else{
			a = (c*b - a) / (1 - c);
			if(a < 0)
				printf("None\n");
			else
				printf("%d\n", a);
		}
	}
	return 0;
}