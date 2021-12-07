#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

vector<vector<int>> f;
vector<int>			v;
string				s;

void calc(bool x) {
	if(x) {
		unsigned int len = v.size();
		sort(v.begin(), v.end());
		for(int i = 0; i < len / 2; i++)
			swap(s[v[len - i - 1]], s[v[i]]);
		f.push_back(v);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		f.clear();
		ll n;

		cin >> n >> s;
		s = " " + s;

		bool flg = true;
		while(flg) {
			flg = false;
			v.clear();
			ll le = 1;
			ll ri = n;
			while(le <= ri) {
				while(s[ri] == '1' && ri)
					ri--;
				while(s[le] == '0' && le <= n)
					le++;
				if(le < ri) {
					flg = true;
					v.push_back(le++);
					v.push_back(ri--);
				}
			}
			calc(flg);
		}
		cout << f.size() << '\n';
		for(auto i : f) {
			cout << i.size() << ' ';
			for(auto j : i)
				cout << j << ' ';
			cout << '\n';
		}
	}

	return 0;
}