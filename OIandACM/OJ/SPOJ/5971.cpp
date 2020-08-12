/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-10 23:43:46
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1e6 + 9;
const ll  mod  = 1e9 + 7;

ll phi[size], ans[size];

void calc() {
	int n = size;
	for(int i = 2; i <= n; i++)
		phi[i] = 0;
	phi[1] = 1;
	for(int i = 2; i <= n; i++)
		if(!phi[i])
			for(int j = i; j <= n; j += i) {
				if(!phi[j])
					phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; i * j <= n; j++) {
			ans[i * j] += j * phi[j] / 2;
		}
	}
	for(int i = 1; i <= n; i++)
		ans[i] = i * ans[i] + i;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	calc();

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << ans[n] << '\n';
	}

	return 0;
}