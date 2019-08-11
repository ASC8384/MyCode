#include <stdio.h>
#include <ctype.h>

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int f[11];

int main()
{
	int k = init();
	int n, a, b;
	int sum;
	char flag;

	while(k--){
		n = init();
		a = init();
		b = init();
		flag = sum = 0;
		for(int i = 1; i <= n; i++)
			f[i] = init();
		for(int i = 1; i <= n; i++){
			if(f[i] < b){
				flag = 1;
				break;
			}
			sum += f[i];
		}
		if(flag || (sum / n <= a && a))
			printf("No\n");
		else{
			printf("Yes\n");
		}
	}
	return 0;
}