#include <bits/stdc++.h>
using namespace std;

unsigned long long a[55];

int main()
{
	int n;
	a[0] = 1;
	a[2] = 3;
	//a[4] = 8;
	for(int i = 4; i <= 50; i += 2)
		a[i] = 4 * a[i-2] - a[i-4];

	while(~scanf("%d", &n) && n != -1){
		if(n & 1)
			printf("0\n");
		else
			printf("%lld\n", a[n]);
	}
	return 0;
}

// 3x != 2n
// 