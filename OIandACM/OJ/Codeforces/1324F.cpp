#include <bits/stdc++.h>
using namespace std;

#define FAST                                                                                       \
	ios_base::sync_with_stdio(false);                                                              \
	cin.tie(NULL);                                                                                 \
	cout.tie(NULL)

const int maxn = 200009;

vector<int> e[maxn];

int n;
int a[maxn];

void dfsson(int now, int fa) {
	for(auto i : e[now]) {
		if(i != fa) {
			dfsson(i, now);
			a[now] += max(0, a[i]);
		}
	}
}

void dfsfat(int now, int so) {
	for(auto i : e[now]) {
		if(i != so) {
			if(a[i] > 0)
				a[i] = max(a[i], a[now]);
			else
				a[i] = max(a[i], a[now] + a[i]);
			dfsfat(i, now);
		}
	}
}

int main() {
	FAST;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = a[i] ? 1 : -1;
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfsson(1, 0);
	dfsfat(1, 0);
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}
