#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	if(a + b > c && a + c > b && b + c > a){
		double d = (a + b + c)/2.0;
		printf("%.2lf", sqrt(d * (d-a) * (d-b) * (d-c)));
	}else{
		printf("Not a triangle.");
	}
	return 0;
}