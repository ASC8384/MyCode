#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 1e5 + 19;
const ll  mod  = 1e9 + 7;

int	 a[size], b[size], c[size], d[size];
int	 n, m, is;
bool ff;
// int m[size], ff[size];
// int ans[size];

queue<int>	q[size];
vector<int> tmp[size], ans;

void clear(queue<int> &q) {
	queue<int> empty;
	swap(empty, q);
}

void init() {
	ff = true;
	is = 0;
	ans.clear();
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		tmp[i].clear();
		d[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		tmp[b[i]].push_back(i);
	}
	for(int i = 1; i <= m; i++)
		cin >> c[i];
}

void calc() {
	for(int i = 1; i <= m; i++) {
		int now = c[i];
		while(d[now] < tmp[now].size() && a[tmp[now][d[now]]] == now) {
			d[now]++;
		}
		if(d[now] < tmp[now].size()) {
			while(is) {
				is--;
				ans.push_back(tmp[now][d[now]]);
			}
			ans.push_back(tmp[now][d[now]]);
			a[tmp[now][d[now]]] = now;
			d[now]++;
		} else if(tmp[now].size() != 0) {
			while(is) {
				is--;
				ans.push_back(tmp[now][0]);
			}
			ans.push_back(tmp[now][0]);
			a[tmp[now][0]] = now;
		} else {
			is++;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] != b[i]) {
			ff = false;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		// int n, mm;
		cin >> n >> m;
		init();
		calc();

		if(is == 0 && ff) {
			cout << "YES\n";
			for(int i = 0; i < m; i++)
				cout << ans[i] << " ";
		} else
			cout << "NO";
		cout << '\n';
	}

	return 0;
}
