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

int a[10009];

int main()
{
	int t = init();

	while(t--){
		int n = init();
		for(int i = 0; i < n; i++)
			a[i] = init();
		int ans = a[1] - a[0];
		int i;
		for(i = 1; i < n; i++)
			if(a[i] != a[i - 1] + ans){
				printf("No\n");
				break;
			}
		if(i == n)
			printf("Yes\n");
	}
	return 0;
}