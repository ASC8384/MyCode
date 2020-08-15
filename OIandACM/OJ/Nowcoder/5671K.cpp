/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-12 13:10:52
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 5e5 + 9;
const ll  mod  = 1e9 + 7;

int a[size];

bool is(int n, int k) {
	int le	= n + 1;
	int ri	= 0;
	int len = 0;
	int tou = 1;
	int num = 0;

	unordered_map<int, int> mp1;
	for(int i = 1; i <= n; i++) {
		if(++mp1[a[i]] > 1) {
			le = i;
			break;
		}
	}
	unordered_map<int, int> mp2;
	for(int i = n; i; i--) {
		if(++mp2[a[i]] > 1) {
			ri = i;
			break;
		}
	}

	if(ri - le + 1 <= 0) {
		return true;
	}
	unordered_map<int, int> mp;
	for(int i = 1; i <= n; ++i) {
		while(mp[a[i]] > len) {
			if(--mp[a[tou]] == len)
				num--;
			tou++;
		}
		if(mp[a[i]]++ == len)
			num++;
		if(num == k) {
			len++;
			num = 0;
			if(tou <= le && i >= ri)
				return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		bool flag = true;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			if(a[i] > k) {
				flag = false;
				// break;
			}
		}
		if(flag && is(n, k)) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}