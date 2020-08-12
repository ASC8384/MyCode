#include <iostream>
using namespace std;

const int size = 5e4 + 9;

long long ans[size];

int main() {
	long long n, m;
	cin >> n >> m;
	long long now = 1;
	long long pos = n;
	for(int i = 1; i <= n; i++) {
		long long tmp = (n - i) * ((n - i) - 1) / 2;
		if(tmp >= m)
			ans[now++] = i;
		else {
			ans[pos--] = i;
			m -= (pos - now + 1);
		}
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	return 0;
}