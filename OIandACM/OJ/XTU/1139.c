#include <stdio.h>
#include <ctype.h>

char is(int x){
	if(x == 1)
		return 0;
	if(x <= 3)
		return 1;
	if(x % 6 != 1 && x % 6 != 5)
		return 0;
	for(register int i = 5; i * i <= x; i += 6)
		if(x % i == 0 || x % (i + 2) == 0)
			return 0;
	return 1;
}

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
	int k;
	int n;
	// scanf("%d", &k);
	k = init();

	while(k--){
		// scanf("%d", &n);
		n = init();
		char f = 0;
		if(n % 2 == 0)
			if(is(2) && is(n >> 1) && 2 != (n >> 1)){
				f = 1;
			}
		for(int i = 3; i * i <= n; i += 2)
			if(n % i == 0)
				if(is(i) && is(n / i) && i != n / i){
					f = 1;
					break;
				}
		if(f)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}