#include <bits/stdc++.h>
using namespace std;

int a[10003];
int m[300];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	string s;
	while(cin >> s) {
		memset(m, -1, sizeof(m));
		int len = s.size();
		int ans = 0;
		int num = 0;
		int lst = 0;
		for(int i = 0; i < len; i++) {
			int ss = s[i] - 'a';
			int mm = m[ss];
			if(mm != -1 && mm >= lst) {
				num = i - mm;
				lst = mm + 1;
			} else
				num++;
			m[ss] = i;
			a[i]  = num;
			ans	  = max(ans, num);
		}
		set<string> ret;
		for(int i = 0; i < len; i++) {
			if(a[i] == ans) {
				ret.insert(s.substr(i - ans + 1, ans));
			}
		}
		cout << ans << '\n';
		for(auto i : ret) {
			cout << i << '\n';
		}
	}
	return 0;
}
