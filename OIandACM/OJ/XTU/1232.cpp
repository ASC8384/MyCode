#include <bits/stdc++.h>
using namespace std;

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main()
{
	int n, m;
	int k = init();

	while(k--){
		n = init();
		m = init();
		if(n && m){
			int a = n * m * 2;
			int b = (n + m) * (n + m - 1);
			if(a % b){
				printf("%d/%d\n", a / __gcd(a, b), b / __gcd(a, b));
			}else{
				printf("%d\n", a / b);
			}
		}else
			printf("0\n");	
	}
	return 0;
}