#include <bits/stdc++.h>
using namespace std;

int isPrime(int n) { //返回1表示判断为质数，0为非质数，在此没有进行输入异常检测
	double n_sqrt;
	if(n == 2 || n == 3)
		return 1;
	if(n % 6 != 1 && n % 6 != 5)
		return 0;
	n_sqrt = floor(sqrt((double)n));
	for(int i = 5; i <= n_sqrt; i += 6) {
		if(n % (i) == 0 | n % (i + 2) == 0)
			return 0;
	}
	return 1;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n == 1)
			cout << "FastestFinger" << endl;
		else if(n & 1 || n == 2)
			cout << "Ashishgup" << endl;
		else {
			// if((n / 2) & 1)
			// 	cout << "FastestFinger" << endl;
			// else {
			int m = n;
			while(n % 2 == 0)
				n /= 2;
			if(n == 1)
				cout << "FastestFinger" << endl;
			else {
				if(m % 4 == 0) {
					cout << "Ashishgup" << endl;
				} else {
					if(isPrime(n))
						cout << "FastestFinger" << endl;
					else
						cout << "Ashishgup" << endl;
				}
				// cout << "Ashishgup" << endl;
				// }
			}
		}
	}
}
