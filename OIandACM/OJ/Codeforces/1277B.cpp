#include <bits/stdc++.h>
using namespace std;

priority_queue<int> q;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, ans, tmp;
		cin >> n;
		ans = 0;
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			q.push(tmp);
		}
		tmp = 0;
		// for(int i = 0; i < n; i++) {
		while(!q.empty()) {
			if(q.top() & 1) {
				q.pop();
			} else {
				if(q.top() == tmp) {
					q.push(q.top() / 2);
					q.pop();
				} else {
					ans++;
					q.push(q.top() / 2);
					tmp = q.top();
					q.pop();
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}