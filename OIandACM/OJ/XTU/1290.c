#include <stdio.h>

char a[23], b[23];

int main()
{
	int n;
	scanf("%d", &n);

	while(n--){
		scanf("%s%s", a, b);
		if(a[0] == 'r' && b[0] == 'r')
			printf("Draw\n");
		if(a[0] == 'r' && b[0] == 'p')
			printf("Bob\n");
		if(a[0] == 'r' && b[0] == 's')
			printf("Alice\n");
		if(a[0] == 'p' && b[0] == 'r')
			printf("Alice\n");
		if(a[0] == 'p' && b[0] == 'p')
			printf("Draw\n");
		if(a[0] == 'p' && b[0] == 's')
			printf("Bob\n");
		if(a[0] == 's' && b[0] == 'r')
			printf("Bob\n");
		if(a[0] == 's' && b[0] == 'p')
			printf("Alice\n");
		if(a[0] == 's' && b[0] == 's')
			printf("Draw\n");
	}
	return 0;
}