#include <bits/stdc++.h>
using namespace std;

inline int init(void){
	char c;
	int x;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main()
{
	int k = init();
	int n, m;
	int a[233];

	while(k--){
		n = init();
		m = init();
		for(int i = 1; i <= n; i++)
			a[i] = init();
		sort(a + 1, a + n + 1);
		int minn = 2e9;
		int top = 1;;
		for(int i = 1; i <= n - m + 1; i++){
			if(a[i + m - 1] - a[i] < minn){
				minn = a[i + m - 1] - a[i];
				top = i;
			}
		}
		int sum = 0;
		for(int i = top; i <= top + m - 1; i++)
			sum += a[i];
		printf("%d %d\n", minn, sum);
	}
	return 0;
}