/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-08-09 22:47:28
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

typedef struct LLL {
	int a, id;
};
LLL aa[size];

bool cmp(LLL x, LLL y) {
	return x.a < y.a;
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
		for(int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			aa[i].a	 = x;
			aa[i].id = i;
		}
		sort(aa + 1, aa + n + 1, cmp);
		int b = 0;
		for(int i = 2; i <= n; i++)
			if(aa[i].id - aa[i - 1].id == 1)
				continue;
			else
				b++;
		b++;
		if(b <= k)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}