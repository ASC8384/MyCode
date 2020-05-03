#include <bits/stdc++.h>
using namespace std;

int n, s, t;
int a[100009];

double	   sum[100009];
deque<int> q;

bool is(double mid) {
	q.clear();
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + (double)a[i] - mid;
	int pos = 0;
	for(int i = s; i <= n; i++, pos++) {
		while(!q.empty() && sum[q.back()] > sum[pos])
			q.pop_back();
		q.push_back(pos);
		while(q.front() < i - t)
			q.pop_front();
		if(sum[i] - sum[q.front()] >= 0)
			return true;
	}
	return false;
}

int main() {
	cin >> n;
	cin >> s >> t;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	double ll = -10000;
	double ri = 10000;
	while(ri - ll > 1e-6) {
		double mid = ll + (ri - ll) / 2.0;
		if(is(mid))
			ll = mid;
		else
			ri = mid;
	}
	// cout << ll
	printf("%.3lf", ll);
	return 0;
}