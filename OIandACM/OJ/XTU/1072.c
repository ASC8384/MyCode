#include <stdio.h>
#include <math.h>

int main()
{
	int x;
	scanf("%d", &x);
	if(0 <= x && x < 10)
		printf("%.5lf", cos(x + 3.0));
	else if(10 <= x && x < 20)
		printf("%.5lf", cos(x+7.5) * cos(x+7.5));
	else if(20 <= x && x < 30)
		printf("%.5lf", cos(x+4.0) * cos(x+4.0) * cos(x+4.0) * cos(x+4.0));
	else
		printf("Not define");
	return 0;
}