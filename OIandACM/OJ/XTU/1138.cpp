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
	int k = init();
	int n, m, a, b;

	while(k--){
		n = init();
		m = init();
		a = (n - m) * (n + m - 1);
		b = n * (n - 1);
		if(a % b){
			int t = __gcd(a, b);
			printf("%d/%d\n", a / t, b / t);
		}else{
			printf("%d\n", a / b);
		}
	}
	return 0;
}