#include <bits/stdc++.h>
using namespace std;

unsigned long long a[55];

int main()
{
	a[1] = 1;
	a[2] = 2;
	for(int i = 3; i <= 50; i++)
		a[i] = a[i-1] + a[i-2];
	int n;

	while(~scanf("%d", &n)){
		printf("%lld\n", a[n]);
	}
	return 0;
}