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
	int t = init();

	while(t--){
		int a = init();
		int b = init();
		int c = init();
		if((c-a) % b)
			printf("%d\n", (c - a) / b + 1);
		else
			printf("%d\n", (c - a) / b);
	}
	return 0;
}