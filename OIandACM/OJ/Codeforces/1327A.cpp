#include <bits/stdc++.h>
using namespace std;

inline int init(void) {
	int	 x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar())
		;
	for(x = 0; isdigit(c); c = getchar())
		x = (x << 1) + (x << 3) + c - '0';
	return x;
}

int main() {
	int t;
	t = init();
	while(t--) {
		// int n = init();
		// int k = init();
		unsigned long long n, k;
		cin >> n >> k;
		if(n % 2 == 0 && k % 2 == 1)
			cout << "NO" << endl;
		else if(n % 2 == 1 && k % 2 == 0)
			cout << "NO" << endl;
		else if(n >= k * k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}