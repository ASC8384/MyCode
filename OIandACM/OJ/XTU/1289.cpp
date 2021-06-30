#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;
int		 f[5432][12][13];

int main() {
	string s;
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	while(cin >> s) {
		int len		   = s.size();
		int num		   = 0;
		int now		   = s[len - 1] - '0';
		memset(f, 0, sizeof(f));
		f[0][0][0]	   = 1;
		f[0][1][now % 3] = 1;
		if(now > 0)
			num += f[0][1][0];
		for(int i = 1; i < len; i++) {
			int now = s[len - i - 1] - '0';
			for(int j = 0; j < 3; j++)
				f[i][0][j] = (f[i - 1][0][j] + f[i - 1][1][j]) % mod;
			for(int j = 0; j < 3; j++)
				f[i][1][(now + j) % 3] = (f[i - 1][0][j] + f[i - 1][1][j]) % mod;
			if(now > 0)
				num += f[i][1][0];
			num %= mod;
		}
		cout << num % mod << '\n';
	}
	return 0;
}
