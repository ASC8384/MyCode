#include <bits/stdc++.h>
using namespace std;

unsigned long long _gcd(unsigned long long a, unsigned long long b){
	return b == 0 ? a : _gcd(b, a % b);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--){
		unsigned long long a, b, c, d;
		// scanf("%I64d%I64d", &a, &b);
		cin >> a >> b;
		while(a > 1){
			unsigned long long tmp = (a + b - 1) / a;
			// int c, d;
			// printf("%I64d ", tmp);
			cout << tmp << " ";
			c = a * tmp - b;
			d = b * tmp;
			unsigned long long gcd = _gcd(d, c);
			a = c / gcd;
			b = d / gcd;
		}
		// if(a == 1)
		// printf("%I64d\n", b);
		cout << b << endl;
	}

	return 0;
}