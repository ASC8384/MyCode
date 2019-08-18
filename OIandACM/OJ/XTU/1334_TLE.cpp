#include <bits/stdc++.h>
using namespace std;

inline unsigned long long init(void){
	unsigned long long x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

unsigned long long a[233];

unsigned long long lcm(unsigned long long x, unsigned long long y, unsigned long long z){
	unsigned long long maxx = max(max(x, y), z);
	unsigned long long ret = maxx;
	while(ret % x || ret % y || ret % z){
		ret += maxx;
	}
	return ret;
}

int main()
{
	unsigned long long t = init();

	while(t--){
		unsigned long long n = init();
		for(unsigned long long i = 0; i < n; i++)
			a[i] = init();
		unsigned long long minn = a[0] * a[1] * a[2];
		for(register int i = 0; i < n; i++)
			for(register int j = i + 1; j < n; j++)
				for(register int k = j + 1; k < n; k++){
					// int ans = a[i] * a[j] / __gcd(__gcd(a[i], a[j]), a[k]) * a[k];
					// is me too navie
					unsigned long long ans = lcm(a[i], a[j], a[k]);
					if(ans < minn)
						minn = ans;
				}
		printf("%I64d\n", minn);
	}
	return 0;
}