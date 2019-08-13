#include <bits/stdc++.h>
using namespace std;

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
		int n = init();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n - i - 1; j++)
				putchar(' ');
			for(int j = 0; j < i + 1; j++)
				putchar('A' + n - j - 1);
			for(int j = i; j; j--)
				putchar('A' + n - j);
			putchar('\n');
		}
		for(int i = n - 2; i >= 0; i--){
			for(int j = 0; j < n - i - 1; j++)
				putchar(' ');
			for(int j = 0; j < i + 1; j++)
				putchar('A' + n - j - 1);
			for(int j = i; j; j--)
				putchar('A' + n - j);
			putchar('\n');
		}
	}
	return 0;
}