#include <bits/stdc++.h>
using namespace std;

unsigned long long f[233];

int logtwo(unsigned long long x){
	if(x == 1)
		return 1;
	int ret = 0;
	unsigned long long n = 1;
	while(n <= x){
		ret++;
		n <<= 1;
	}
	return ret-1;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	unsigned long long t, n;
	cin >> t;

	f[0] = 0;
	f[1] = 1;
	f[2] = 2;
	for(int i = 3; i <= 100; i++)
		f[i] = f[i-1] + f[i-2];

	while(t--){
		cin >> n;
		cout << f[logtwo(n)] << endl;
	}
	return 0;
}