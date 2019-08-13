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
	int t = init();

	while(t--){
		int x = init();
		int y = init();
		if(x == y)
			printf("1/%d\n", x);
		else{
			int a = 1;
			int b = x;
			for(x++; x <= y; x++){
				a = a * x + b;
				b = b * x;
			}
			if(a % b)
				printf("%d/%d\n", a / __gcd(a, b), b / __gcd(a, b));
			else
				printf("%d\n", a / b);
		}
	}
	return 0;
}