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
				if(b == 0)
					printf("1\n");
				else
					printf("0\n");
			else
				printf("None\n");
		else{
			//a = (c*b - a) / (1 - c);
			if(b == 0 && a == 0)
				printf("None\n");
			else
				if((c*b - a) % (1 - c))
					printf("None\n");
				else
					if((c*b - a) / (1 - c) < 0)
						printf("None\n");
					else
						printf("%d\n", (c*b - a) / (1 - c));
		}
	}
	return 0;
}