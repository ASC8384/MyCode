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

//int s[] = {11, 1001, 100001, 101101, 110011};// 5 100000
 int a[] = {11, 1001, 1111, 100001, 101101, 110011, 111111};//7

int main()
{
	int t = init();

	while(t--){
		int m = init();
		int ans = 0;
		int minn = 100000;

		for(int i = 6; i >= 0; i--){
			int n = m;
			while(a[i] <= n){
				n -= a[i];
				ans++;
			}
			for(int j = i - 1; j >= 0; j--){
				while(a[j] <= n){
					n -= a[j];
					ans++;
				}
			}
			if(n == 0)
				minn = min(minn, ans);
			ans = 0;
		}
		if(minn == 100000)
			printf("0\n");
		else
			printf("%d\n", minn);
	}
	return 0;
}