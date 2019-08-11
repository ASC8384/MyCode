#include <stdio.h>

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

int main()
{
	int k;
	int n;
	scanf("%d", &k);

	while(k--){
		scanf("%d", &n);
		char f = 0;
		for(int i = 2; i <= (n >> 1); i++)
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