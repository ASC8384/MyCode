#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		// s.clear();
		stack<int> s;
		int		   n;
		cin >> n;
		int minn = 0x7fffffff;
		while(n--) {
			string ss;
			cin >> ss;
			if(ss == "MIN") {
				if(minn == 0x7fffffff)
					cout << "NULL\n";
				else
					cout << minn << '\n';
			} else if(ss == "PUSH") {
				int tmp;
				cin >> tmp;
				if(tmp < minn) {
					s.push(minn);
					minn = tmp;
				}
				s.push(tmp);
			} else {
				if(s.top() == minn) {
					s.pop();
					minn = s.top();
					s.pop();
				} else {
					s.pop();
				}
			}
		}
	}

	return 0;
}
