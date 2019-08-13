#include <bits/stdc++.h>
using namespace std;

inline unsigned long long init(void){
	unsigned long long x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main()
{
	unsigned long long t = init();

	while(t--){
		unsigned long long x = init();
		unsigned long long y = init();
		if(x == y)
			printf("1/%I64d\n", x);
		else{
			unsigned long long a = 1;
			unsigned long long b = x;
			unsigned long long t;
			for(x++; x <= y; x++){
				a = a * x + b;
				b = b * x;
				t = __gcd(a, b);
				a /= t;
				b /= t;
			}
			t = __gcd(a, b);
			if(a % b)
				printf("%I64d/%I64d\n", a / t, b / t);
			else
				printf("%I64d\n", a / b);
		}
	}
	return 0;
}