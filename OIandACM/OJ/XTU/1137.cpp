#include <cstdio>
#include <cctype>

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
	char c;
	// scanf("%d", &k);???????
	k = init();

	while(k--){
		scanf("%s", &c);
		for(int i = 'A'; i <= c; i++){
			for(int j = 0; j <= c - 'A'; j++)
				putchar(' ');
			putchar(i);
			putchar('\n');
			for(int j = 1; j <= c - i; j++)
				putchar(' ');
			for(int j = 1; j <= 1 + ((i - 'A' + 1) << 1); j++)
				putchar(i);
			putchar('\n');
		}
	}
	return 0;
}