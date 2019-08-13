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

void prt(int n, char c){
	for(int i = 1; i <= n; i++)
		putchar(c);
}

int main()
{
	int t = init();

	while(t--){
		int n = init();
		prt(n - 1, '-');
		putchar('\n');
		putchar('\\');
		prt(n - 3, ' ');
		putchar('/');
		putchar('\n');
		for(int i = 1; i < (n >> 1) - 1; i++){
			prt(i, ' ');
			putchar('\\');
			prt(n - 3 - i * 2, '*');
			putchar('/');
			putchar('\n');
		}
		for(int i = 1; i < (n >> 1); i++){
			prt((n >> 1) - 1 - i, ' ');
			putchar('/');
			prt(i - 1, ' ');
			putchar('*');
			prt(i - 1, ' ');
			putchar('\\');
			putchar('\n');
		}
		for(int i = 1; i < n; i++)
			putchar('-');
		putchar('\n');
		putchar('\n');
	}
	return 0;
}

/*

-------
\     /
 \***1
  \1/
  2*\
 1 * \
0  *  \
-------

-----
\   /
 \*/
 /*\
/ * \
-----

*/