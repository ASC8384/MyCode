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
	int t;

	while(k--){
		t = init();
		if(t < 100)
			printf("%d\n", 200 - 3 * (100 - t));
		else
			printf("%d\n", 200 + 2 * (t - 100));
	}
	return 0;
}