#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	int a, b, c, d, e;
	cin >> k;

	while(k--){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a = a * d;
		e = b * c;
		c = b * d;//bd
		d = a + e;//ad + bc
		a = a - e;//ad - bc

		if(d % c == 0)
			printf("%d ", d / c);
		else{
			b = __gcd(d, c);
			printf("%d/%d ", d / b, c / b);
		}

		if(a % c == 0)
			printf("%d\n", a / c);
		else{
			b = abs(__gcd(a, c));
			if(a < 0)
				printf("-%d/%d\n", abs(a) / b, c / b);
			else
				printf("%d/%d\n", a / b, c / b);
		}
	}
	return 0;
}