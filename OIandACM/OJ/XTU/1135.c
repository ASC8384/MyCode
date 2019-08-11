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
	int n;
	n = init();

	while(n--){
		printf("%d\n", init() + init() + init() + init() + init());
	}
	return 0;
}