/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-01-24 22:21:17
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e6 + 9;
const ll  mod  = 1e9 + 7;

// bool vis[size];
ll cnt;

struct trie {
	ll	 ch[size][36];
	bool is[size];
	void insert(string s, int len) { // char *s
		int p = 1;
		for(int i = 0; i < len; i++) {
			int c = s[i] - 'a';
			if(!ch[p][c])
				ch[p][c] = ++cnt;
			p = ch[p][c];
		}
		is[p] = true;
	}
	int find(string s, int len) {
		int p = 1;
		for(int i = 0; i < len; i++) {
			int c = s[i] - 'a';
			if(!ch[p][c])
				return 0;
			p = ch[p][c];
		}
		if(!is[p])
			return 1;
		is[p] = false;
		return 2;
	}
} t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cnt = 1;
	// memset(&t, 0, sizeof(trie));
	// t.cnt = 1;
	// freopen("../in.txt", "r", stdin);
	// freopen("../out.txt", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		t.insert(s, s.size());
		// cout << i << endl;
	}

	int m;
	cin >> m;
	for(int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		int tmp = t.find(s, s.size());
		// cout << i << endl;
		if(tmp == 2)
			cout << "OK\n";
		else if(tmp == 1)
			cout << "REPEAT\n";
		else
			cout << "WRONG\n";
	}

	return 0;
}