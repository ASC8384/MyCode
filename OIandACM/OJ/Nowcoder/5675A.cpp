#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int	 a[size];
int	 p;
int	 top;
bool f[size];

void dfs(int x) {
	f[x]	 = true;
	a[++top] = x;
	if(top == p - 1)
		return;
	if(!f[(x * 2 % p)])
		dfs(x * 2 % p);
	else if(!f[(x * 3 % p)])
		dfs(x * 3 % p);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		cin >> p;
		top = 0;
		memset(f, 0, sizeof(f));
		dfs(1);
		if(p - 1 == top) {
			for(int i = 1; i <= top; i++)
				cout << a[i] << " ";
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}
	}

	return 0;
}