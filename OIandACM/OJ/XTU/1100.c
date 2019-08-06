#include <stdio.h>

int main()
{
	int n;
	int b, h;
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &b, &h);
		printf("%.1f\n", b * h / 2.0);
	}
	return 0;
}