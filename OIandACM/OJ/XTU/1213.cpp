#include <bits/stdc++.h>
using namespace std;

inline int init(void){
	char c;
	int x;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main()
{
	int n = init();
	int x, y;

	while(n--){
		y = init();
		x = init();
		x = x * (x - 1) * (x - 2);
		y = y * (y - 1) * (y - 2);
		if(x % y)
			printf("%d/%d\n", x / __gcd(x, y), y / __gcd(x, y));
		else
			printf("%d\n", x / y);
	}
	return 0;
}