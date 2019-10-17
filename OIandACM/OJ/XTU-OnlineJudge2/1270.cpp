#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	double s, a, b, v;
	scanf("%d", &t);
	
	while(t--){
		scanf("%lf%lf%lf%lf", &s, &a, &b, &v);
		double tmpa = v * v / 2.0 / a;
		double tmpb = v * v / 2.0 / b;
		//printf("%lf\n", tmp);
		if(tmpa + tmpb > s - 0.00001){
			double tmp = sqrt(2.0*s/(a+a*a/b));
			printf("%.2lf\n", tmp+a*tmp/b);
			//printf("%.2lf\n", sqrt(2*s*b/(a+b)) + sqrt(2*s*b/(a+b))*a/b);
		}else{
			printf("%.2lf\n", (v/a) + (v/b) + ((s - tmpa - tmpb)/v));
		}
	}
	return 0;
}