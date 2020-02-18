#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool is_root[6666];
bool vis[6666];
int  father[6666];
int  v[6666]; // no
int  f[6666]; // yes
int  n;
int  a, b;
int  root = 0;

void dfs(int node) {
	vis[node] = true;
	for(int i = 1; i <= n; i++) {
		if(!vis[i] && father[i] == node) {
			dfs(i);
			f[node] += v[i];
			v[node] += max(v[i], f[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> f[i];

	while(cin >> a >> b && a != 0 && b != 0) {
		father[a]  = b;
		is_root[a] = true;
	}

	for(int i = 1; i <= n; i++)
		if(!is_root[i]) {
			root = i;
			break;
		}

	dfs(root);
	cout << max(f[root], v[root]) << endl;

	return 0;
}