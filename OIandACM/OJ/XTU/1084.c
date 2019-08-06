#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, p;
	scanf("%lg %lg %lg", &a, &b, &p);
	printf("%g\n", sqrt(a*a + b*b - 2.0*a*b*cos(p/180.0*3.14159265)));
	return 0;
}