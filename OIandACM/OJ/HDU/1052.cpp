/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-18 11:13:34
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1000 + 9;
const ll  mod  = 1e9 + 7;

int a[size], b[size];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	while(cin >> n && n) {
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		int win = 0;
		int los = 0;
		int as	= 1;
		int bs	= 1;
		int ae	= n;
		int be	= n;
		for(int i = 1; i <= n; i++) {
			if(a[as] > b[bs]) {
				win++;
				as++;
				bs++;
			} else {
				if(a[as] < b[bs]) {
					los++;
					as++;
					be--;
				} else {
					if(a[ae] > b[be]) {
						win++;
						ae--;
						be--;
					} else {
						if(a[as] < b[be])
							los++;
						be--;
						as++;
					}
				}
			}
		}
		cout << 200 * (win - los) << '\n';
	}

	return 0;
}