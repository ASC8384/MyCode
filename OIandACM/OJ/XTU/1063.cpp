#include <bits/stdc++.h>
#define ll __int64
using namespace std;

int main()
{
	long long n;
	cin >> n;
	cout << n << ",";
	//printf("%I64d,", n);
	char c[2333] = {'0'};
	int top = 0;
	while(n){
		if(n % 16 > 9)
			c[++top] = n%16 - 10 + 'A';
		else
			c[++top] = n%16 + '0';
		n /= 16;
	}
	for(int i = top; i > 0; i--)
		cout << c[i];
	return 0;
}