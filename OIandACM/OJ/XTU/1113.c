#include <stdio.h>

int main()
{
	int n;
	int a, b, c, d;
	scanf("%d", &n);

	while(n--){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if((c <= a && b <= d) ||
			(a <= c && c <= b && b <= d) ||
			(a <= c && d <= b) ||
			(c <= a && a <= d && d <= b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}