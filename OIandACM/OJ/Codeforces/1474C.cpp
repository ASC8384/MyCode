#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e6 + 9;
const ll  mod  = 1e9 + 7;

int a[2333];
int dp[2333];
// int	 f[size];
int	 n;
bool is;

unordered_map<int, int> f;
vector<int>				ans;

void dfs(int now, int sum) {
	if(sum == 2) {
		if(true)
			is = true;
		else
			return;
	}
	if(is)
		return;
	if(dp[now])
		return;
	if(f[a[now - 1]] && f[a[now] - a[now - 1]]) {
		f[a[now - 1]]--;
		f[a[now] - a[now - 1]]--;
		// ans.push_back({a[now], a[now - 1]});
		dfs(now - 1, sum - 1);
		ans.pop_back();
		f[a[now - 1]]++;
		f[a[now] - a[now - 1]]++;
	}
	if(f[a[now - 2]] && f[a[now] - a[now - 2]]) {
		f[a[now - 2]]--;
		f[a[now] - a[now - 2]]--;
		// ans.push_back({a[now], a[now - 2]});
		dfs(now - 2, sum - 2);
		ans.pop_back();
		f[a[now - 2]]++;
		f[a[now] - a[now - 2]]++;
	}
	dp[now] = true;
}

bool ok(int num, int now) {
	ans[now] = 0;
	if(now == 0)
		return true;
	if(f[a[now]] == 0)
		return ok(num, now - 1);
	f[a[now]]--;
	if(num <= 2 * a[now] && f[num - a[now]] != 0) {
		f[num - a[now]]--;
		if(ok(a[now], now - 1)) {
			ans[now] = num - a[now];
			return true;
		}
		f[num - a[now]]++;
	}
	f[a[now]]++;
	return false;
}

void prt(bool is) {
	if(is) {
		cout << "YES\n";
		cout << a[n] + ans[n] << '\n';
		for(int i = n; i; i--)
			if(ans[i])
				cout << a[i] << " " << ans[i] << '\n';
	} else
		cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		// int n;
		cin >> n;
		n <<= 1;
		int now = 0;
		ans.clear();
		// memset(f, 0, sizeof(f));
		f.clear();
		ans.resize(n + n);
		is = false;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			f[a[i]]++;
		}
		sort(a + 1, a + n + 1);
		f[a[n]]--;
		for(int i = 1; i < n; i++) {
			f[a[i]]--;
			if(ok(a[n], 2 * n - 1)) {
				ans[n] = a[i];
				is	   = true;
				break;
			}
			f[a[i]]++;
		}
		prt(is);

		/*for(int an = 1; an < n; an++) {
			ans.push_back({a[n], a[n - an]});
			f[a[n]]--;
			f[a[n - an]]--;
			dfs(n, n);
			if(is) {
				cout << "YES\n";
				cout << a[n] + a[an] << '\n';
				for(int i = 0; i < ans.size(); i++) {
					cout << ans[i].first << ' ' << ans[i].second << '\n';
				}
				break;
			}
			f[a[n]]++;
			f[a[n - an]]++;
			ans.clear();
		}
		if(!is) {
			cout << "NO\n";
		}*/
	}

	return 0;
}