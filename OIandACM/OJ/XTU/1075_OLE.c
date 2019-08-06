#include <stdio.h>

inline long long gcd(long long a, long long b){
	long long t;
	while(b){
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	long long x, y;
	scanf("%lld%lld", &x, &y);
	while(x != 0 && y != 0){
		printf("%lld\n", x * y / gcd(x, y));
		scanf("%lld%lld", &x, &y);
	}
	return 0;
}