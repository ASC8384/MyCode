#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int	size = 2e5 + 9;
const ll	mod	 = 1e9 + 7;
const int	N	 = 5e6 + 2;
vector<int> fac[N];

void init() {
	for(int i = 2; i < N; i++) {
		for(int j = i; j < N; j += i) {
			fac[j].push_back(i);
		}
	}
}

int A[30];

int main() {
	ios::sync_with_stdio(0);
	srand(time(NULL));
	cin.tie(0);
	cout.tie(0);
	// init();
	int t = 1;
	cin >> t;
	while(t--) {
		int	   n;
		string s;
		cin >> n;
		cin >> s;
		if(n == 1) {
			cout << "No" << '\n';
			continue;
		}
		bool flag = true;
		int	 len  = s.size();
		for(int i = 1; i < len; i++)
			if(s[0] != s[i]) {
				flag = false;
				break;
			}
		if(flag) {
			cout << "Yes" << '\n';
			continue;
		}
		memset(A, 0, sizeof(A));
		for(int i = 0; i < n; i++)
			A[s[i] - 'a']++;
		int k = 0;
		for(int i = 0; i <= 25; i++)
			if(A[i])
				k = __gcd(A[i], k);
		if(k == 1) {
			cout << "No" << '\n';
			continue;
		}
		for(int i = sqrt(n); i >= k; i--) {
			// cout << i << '\n';
			if(n % i)
				continue;
			flag = true;
			string ss(s, 0, i);
			ss = ss + ss;
			// get(ss);
			for(int j = i + 1; j <= n; j += i) {
				string tmp(s, j - 1, i);
				if(ss.find(tmp) == std::string::npos) {
					// if(!is(ss, tmp)) {
					flag = false;
					break;
				}
			}
			if(flag) {
				break;
			}
			int now = n / i;
			flag	= true;
			string sss(s, 0, now);
			sss = sss + sss;
			// get(sss);
			for(int j = now + 1; j <= n; j += now) {
				string tmp(s, j - 1, now);
				// if(!is(sss, tmp)) {
				if(sss.find(tmp) == std::string::npos) {
					flag = false;
					break;
				}
			}
			if(flag) {
				break;
			}
		}
		if(flag) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}

	return 0;
}