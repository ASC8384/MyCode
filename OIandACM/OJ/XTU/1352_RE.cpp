#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--){
		unsigned long long a, b, c, d;
		scanf("%lld%lld", &a, &b);
		while(a >= 1){
			unsigned long long tmp = (a + b - 1) / a;
			// int c, d;
			printf("%lld ", tmp);
			c = a * tmp - b;
			d = b * tmp;
			unsigned long long gcd = __gcd(d, c);
			a = c / gcd;
			b = d / gcd;
		}
		// if(a == 1)
		printf("\n");
	}

	return 0;
}