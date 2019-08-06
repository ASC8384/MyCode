#include <stdio.h>

inline __int64 gcd(__int64 a, __int64 b){
	__int64 t;
	while(b){
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	__int64 x, y;
	scanf("%I64d%I64d", &x, &y);
	while(x != 0 && y != 0){
		if(x > y)
			printf("%I64d\n", x * y / gcd(x, y));
		else
			printf("%I64d\n", x * y / gcd(y, x));
		scanf("%I64d%I64d", &x, &y);
	}
	//putchar('\n');
	return 0;
}