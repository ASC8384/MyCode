#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int fa1[size], fa2[size];

int find1(int x) {
	return x == fa1[x] ? x : (fa1[x] = find1(fa1[x]));
}

void merge1(int i, int j) {
	fa1[find1(i)] = find1(j);
}

int find2(int x) {
	return x == fa2[x] ? x : (fa2[x] = find2(fa2[x]));
}

bool find1(int x, int y){
    return find1(x) == find1(y);
}

bool find2(int x, int y){
    return find2(x) == find2(y);
}

void merge2(int i, int j) {
	fa2[find2(i)] = find2(j);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m1, m2;
	cin >> n >> m1 >> m2;
	for(int i = 1; i <= n; i++) {
		fa1[i] = fa2[i] = i;
	}
	for(int i = 1; i <= m1; i++) {
		int u, v;
		cin >> u >> v;
		merge1(u, v);
	}
	for(int i = 1; i <= m2; i++) {
		int u, v;
		cin >> u >> v;
		merge2(u, v);
	}
	int n1 = n - m1;
	int n2 = n - m2;
    vector<pair<int, int>> v;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(!find1(i, j) && !find2(i, j) && n1 > 1 && n2 > 1) {
				merge1(i, j);
				merge2(i, j);
				n1--;
				n2--;
				v.push_back({i, j});
			}
	cout << v.size() << '\n';
	for(auto i : v)
		cout <<  i.first << ' ' << i.second << '\n';

	return 0;
}