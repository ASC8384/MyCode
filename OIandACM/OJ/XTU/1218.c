#include <stdio.h>
#include <ctype.h>

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

	while(k--){
		int ans = 1;
		int n = init() + init();
		for(int i = 2; i * i <= n; i++)
			if(n % i == 0){
				int cnt = 1;
				while(n % i == 0){
					n /= i;
					cnt++;
				}
				ans *= cnt;
			}
		if(n != 1)
			ans <<= 1;// 2
		printf("%d\n", ans);
	}
	return 0;
}