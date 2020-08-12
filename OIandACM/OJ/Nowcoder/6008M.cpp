#include <bits/stdc++.h>
using namespace std;

int f[100009];

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int ans = 0;
	for(int i = a; i <= d; i++)
		f[i] = max(f[i], f[i - a] + 1);
	for(int i = b; i <= d; i++)
		f[i] = max(f[i], f[i - b] + c);
	cout << f[d];
	return 0;
}