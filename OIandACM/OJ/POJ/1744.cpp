/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-17 09:55:56
*/
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const int size = 3e4 + 9;
const ll  mod  = 1e9 + 7;

int	 f;
int	 top;
bool v[size];

bool is(int t) {
	int num = 0;
	// int i	= t / 20 + 2;
	// while(i <= top) {
	for(int i = t / 20 + 2, j; i <= top; i++) {
		while(!v[i] && i <= top)
			i++;
		if(4 * (i - 1) + 10 * num > t)
			return false;
		j = (t - 10 * num + 20 * i + 4) / 24;
		i = (t - 10 * num + 16 * j + 4) / 20;
		num++;
	}
	return true;
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int n;
	// while(cin >> n && n) {
	while(scanf("%d", &n) && n) {
		memset(v, 0, sizeof(v));
		top = 0;
		for(int i = 1; i <= n; i++) {
			// cin >> f;
			scanf("%d", &f);
			v[f] = true;
			if(f > top)
				top = f;
		}
		int le = 0;
		int ri = (top - 1) * 20;
		while(le < ri) {
			int mid = (ri - le) / 2 + le;
			if(is(mid)) {
				ri = mid;
			} else {
				le = mid + 1;
			}
		}
		// cout << le << '\n';
		printf("%d\n", le);
		// for(int i = 1; i <= top; i++) {
		// 	v[i] = false;
		// }
	}

	return 0;
}