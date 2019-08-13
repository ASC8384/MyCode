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

void prt_(int n){
	for(int i = 1; i <= n; i++)
		putchar(' ');
}

void prtA(int n){
	for(int i = 1; i <= n; i++)
		putchar(64 + i);
}

void prtZ(int n){
	for(int i = n; i >= 1; i--)
		putchar(64 + i);
}

int main()
{
	char c;

	while(~scanf("%c", &c)){
		int n = c - 'A' + 1;
		for(int i = 1; i <= n; i++){
			prt_(2 * n - i);
			prtA(i);
			prtZ(i - 1);
			putchar('\n');
		}
		for(int i = 1; i <= n; i++){
			prt_(n - i);
			prtA(i);
			prtZ(i - 1);
			prt_(1 + 2 * (n - i));
			prtA(i);
			prtZ(i - 1);
			putchar('\n');
		}
	}
	return 0;
}