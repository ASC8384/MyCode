#include <bits/stdc++.h>

inline unsigned int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

inline bool is_prime(unsigned int n){
    if(n == 1)
    	return false;
    if(n == 2 || n == 3)
    	return true;
    if(n % 6 != 1 && n % 6 != 5)
    	return false;
    for(register int i = 5; i * i <= n; i += 6)
        if(n % i == 0 || n % (i+2) == 0)
        	return false;
    return true;
}

int main()
{
	unsigned int n = init();
	while(n != 0){
		if(is_prime(n))
			printf("Yes\n");
		else
			printf("No\n");
		n = init();
	}
	return 0;
}