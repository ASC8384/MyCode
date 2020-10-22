#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);

	double h, s1, v, l, k;
	int	   n;
	cin >> h >> s1 >> v >> l >> k >> n;

	double maxx = sqrt(h / 5.0);
	double minn = sqrt((h - k) / 5.0);
	int	   ans	= min(int(s1 - minn * v + l), n) - max(int(s1 - maxx * v), 0);
	cout << ans;

	return 0;
}