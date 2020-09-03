#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 200 + 9;
const ll  mod  = 1e9 + 7;

struct un {
	int id, val;
} a[size];

bool cmp(un x, un y) {
	if(x.val == y.val)
		return x.id < y.id;
	return x.val > y.val;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i++) {
			a[i].id = i;
			cin >> a[i].val;
		}
		sort(a + 1, a + n + 1, cmp);
		if(k == 0) {
			for(int i = 1; i < n; i++)
				cout << i << " ";
			cout << n;
		} else {
			for(int i = 1; i < n; i++)
				cout << a[i].id << " ";
			cout << a[n].id;
		}
		cout << '\n';
	}

	return 0;
}