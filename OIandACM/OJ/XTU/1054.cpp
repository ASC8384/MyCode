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
	__int64 a[1009], b[1009];
	int n = init();
	int ans;

	while(n != 0){
		ans = 0;
		for(int i = 0; i < n; i++){
			a[i] = init();
			b[i] = a[i] * a[i];
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(a[i] == b[j])
					ans++;
		cout << ans << endl;
		n = init();
	}
	return 0;
}
// x  == y