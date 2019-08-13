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

bool cmp(const pair<string, unsigned long long>& x, const pair<string, unsigned long long>& y){
	if(x.second == y.second)
		return x.first < y.first;
	return x.second > y.second;
}

// map<unsigned long long, unsigned long long> a;
map<string, unsigned long long> a;

int main()
{
	ios::sync_with_stdio(false);
	unsigned long long ti, pa;
	//unsigned long long xu;
	string xu;

	// while(scanf("%d%I64d%d", &ti, &xu, &pa) == 3){
	while(cin >> ti >> xu >> pa){
		if(1 <= pa && pa <= 12)
			a[xu] += 32;else
		if(13 <= pa && pa <= 24)
			a[xu] += 16;else
		if(25 <= pa && pa <= 48)
			a[xu] += 8;else
		if(49 <= pa && pa <= 96)
			a[xu] += 4;else
		if(97 <= pa && pa <= 192)
			a[xu] += 2;
		else
			a[xu] += 1;
	}
	vector<pair<string, unsigned long long>> b(a.begin(), a.end());
	sort(b.begin(), b.end(), cmp);
	unsigned long long maxn = b[0].second;
	cout << maxn << endl;
	for(unsigned long long i = 0; i < b.size(); i++)
		// printf("%d %.0lf\n", b[i].first, 100 + 10.0 * log((double)b[i].second / (double)maxn));
		cout << b[i].first << " " << floor(100 + 10.0 * log((double)b[i].second / (double)maxn)) << endl;
	return 0;
}