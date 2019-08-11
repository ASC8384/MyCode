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
	int n = init();
	int ans, tmp;

	while(n){
		ans = 0;
		tmp = 1;
		do{
			ans++;
			if(tmp > n)
				tmp = ((tmp - n) << 1) - 1;
			else
				tmp <<= 1;
		}while(tmp != 1);
		printf("%d\n", ans);
		n = init();
	}
	return 0;
}