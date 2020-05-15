#include <bits/stdc++.h>
using namespace std;

struct node {

	int			l;
	int			r;
	int			len;
	friend bool operator<(node n1, node n2) {
		if(n1.len == n2.len) {
			return n1.l > n2.l;
		}
		return n1.len < n2.len;
	}
};
priority_queue<node> Q;

int ans[500009];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		Q.push({1, n, n});
		for(int i = 1; i <= n; ++i) {
			node tmp = Q.top();
			Q.pop();
			int l	= tmp.l;
			int r	= tmp.r;
			int len = tmp.len;
			int mid;
			if((r - l + 1) % 2 == 1) {
				ans[(tmp.r + tmp.l) / 2] = i;

				mid = (tmp.r + tmp.l) / 2;
			} else {
				ans[(tmp.r + tmp.l - 1) / 2] = i;

				mid = (tmp.r + tmp.l - 1) / 2;
			}
			Q.push({l, mid - 1, mid - 1 - l + 1});
			Q.push({mid + 1, r, r - (mid + 1) + 1});
		}
		while(!Q.empty())
			Q.pop();
		for(int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
