#include <stdio.h>

double f(int n){
	if(n)
		return n * f(n - 1);
	return 1;
}

int main()
{
	int n, m, k;
	scanf("%d", &k);

	while(k--){
		scanf("%d%d", &n, &m);
		if((n + m) & 1){
			printf("0\n");
		}else if(n == m){
			printf("1\n");
		}else{
			printf("%.0lf\n", f(n)/f((n + m) >> 1)/f((n - m) >> 1));
		}
	}
	return 0;
}
