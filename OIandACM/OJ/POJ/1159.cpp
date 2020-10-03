#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int	   n;
short  f[5001][5001];
string s, a;

int max(int x, short y) {
	return (x > y) ? x : y;
}

int main() {
	scanf("%d", &n);
	cin >> s;
	a = s;
	reverse(s.begin(), s.end());

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(s[i] == a[j])
				f[i + 1][j + 1] = f[i][j] + 1;
			else
				f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
			ans = max(ans, f[i + 1][j + 1]);
		}
	}
	printf("%d", n - ans);

	return 0;
}
