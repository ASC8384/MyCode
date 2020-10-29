#include <algorithm>
#include <cstdio>
#include <iostream>
// #include <map>
// #include <unordered_map>
using namespace std;

int a[5000];
int b[5000];
int c[5000];
int d[5000];
int n;

const int size = 20192023;
const int maxn = 1112345678;
const int key  = 1321;
int		  has[size];
int		  sum[size];

void insert(int x) {
	int tmp = x;
	x		= (x + maxn) % size;
	while(has[x] != maxn && has[x] != tmp) {
		x = x + key;
		if(x >= size)
			x -= size;
	}
	has[x] = tmp;
	sum[x]++;
}

int find(int x) {
	int tmp = x;
	x		= (x + maxn) % size;
	while(has[x] != maxn && has[x] != tmp) {
		x = x + key;
		if(x >= size)
			x -= size;
	}
	if(has[x] == maxn)
		return 0;
	return sum[x];
}

int main() {
	//ios::sync_with_stdio(false);
	int i, j;
	int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < size; i++)
			has[i] = maxn, sum[i] = 0;
		// unordered_map<int, int> mp;
		for(i = 0; i < n; i++)
			scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				// mp[a[i] + b[j]]++;
				insert(a[i] + b[j]);
			}
		}
		int ans = 0;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				// ans += mp[-c[i] - d[j]];
				ans += find(-c[i] - d[j]);
				//cout<<c[i]<<" "<<d[i]<<endl;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
