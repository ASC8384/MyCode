/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-11-21 22:55:51
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int	   a[size];
string s1, s2;

//unordered_map<char, int> mp1, mp2;
int mp1[33];
int mp2[33];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		s1.clear();
		s2.clear();
		memset(mp1, 0, sizeof(mp1));
		memset(mp2, 0, sizeof(mp2));
		// mp1.clear();
		// mp2.clear();

		int n, k;
		cin >> n >> k;
		cin >> s1 >> s2;

		for(int i = 0; i < n; i++)
			mp1[s1[i] - 'a']++, mp2[s2[i] - 'a']++;
		bool flg = true;
		for(int i = 0; i <= 30; i++) {
			if(mp1[i] == mp2[i])
				continue;
			if(mp1[i] < mp2[i]) {
				flg = false;
				goto ANS;
			}
			if((mp1[i] - mp2[i]) % k == 0) {
				mp1[i + 1] += k * ((mp1[i] - mp2[i]) / k);
			} else {
				flg = false;
				goto ANS;
			}
		}
	ANS:
		if(flg)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}