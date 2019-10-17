#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	int s, a, b, v;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d%d%d", &s, &a, &b, &v);
		double tmp = v * v / 2.0 / (double)a;
		//printf("%lf\n", tmp);
		if(tmp > s + 0.0000001){
			tmp = sqrt(2*s/(double)(a+a*a/(double)b));
			printf("%.2lf\n", t+a*t/(double)b);
			//printf("%.2lf\n", (double)sqrt(2*s*b/(double)(a+b)) + (double)sqrt(2*s*b/(double)(a+b))*a/(double)b);
		}else{
			printf("%.2lf\n", (v/(double)a) + (v/(double)b) + ((s - tmp - v * v / 2.0 / (double)b)/(double)v));
		}
	}
	return 0;
}