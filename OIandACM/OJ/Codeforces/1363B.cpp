#include <bits/stdc++.h>
using namespace std;
typedef long long		   ll;
typedef unsigned long long ull;
const ll				   size = 5e5 + 9;
inline void				   qread() {}
template <class T1, class... T2>
inline void qread(T1 &IEE, T2 &... ls) {
	register T1	  __ = 0, ___ = 1;
	register char ch;
	while(!isdigit(ch = getchar()))
		___ = (ch == '-') ? -___ : ___;
	do {
		__ = (__ << 1) + (__ << 3) + (ch ^ 48);
	} while(isdigit(ch = getchar()));
	__ *= ___;
	IEE = __;
	qread(ls...);
	return;
}

int main() {
	int t;
	qread(t);
	while(t--) {
		string s;
		cin >> s;
		int ll	= s.size();
		int sum = 0;
		int cnt = 0;
		for(int i = 0; i < ll; i++) {
			sum += s[i] - '0';
			if(s[i] == '0')
				cnt++;
		}
		int ans = 0x7fffffff;
		ans		= min(ll - sum, ans);
		ans		= min(ll - cnt, ans);
		for(int i = 0; i < ll; i++) {
			int tmp00 = 0, tmp11 = 0, cnt0 = 0, cnt1 = 0;
			for(int j = 0; j < i; j++) {
				if(s[j] == '0')
					tmp00++;
				else
					tmp11++;
			}
			for(int k = i; k < ll; k++) {
				if(s[k] == '0')
					cnt0++;
				else
					cnt1++;
			}
			ans = min(cnt1 + tmp00, ans);
			ans = min(tmp11 + cnt0, ans);
		}
		cout << ans << "\n";
	}
	return 0;
}