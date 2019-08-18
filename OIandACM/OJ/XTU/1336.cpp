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
	// freopen("std.in", "r", stdin);
	// freopen("std.out", "w", stdout);

	int t = init();

	while(t--){
		int n = init();
		if(n % 11){
			printf("0\n");
		}else{
			int minn = 100000;
			for(int i = 0; i <= n / 1111; i++){
				int tmp = n - 1111 * i;// 还剩下多少
				minn = min(minn, i + // 1111
								 tmp / 1001 + // 1001
								 tmp % 1001 / 11 // 11
								 );
			}
			printf("%d\n", minn);
		}
	}
	return 0;
}