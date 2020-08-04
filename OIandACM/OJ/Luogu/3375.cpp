/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-03 21:20:12
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string	  s1, s2;
const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;
int		  kmp[size];
// vector<int> kmp;
// vector<int> a;

void getnext(string s) { // begin 1
	kmp[0] = -1;
	int n  = (int)s.size();
	for(int i = 0, j = -1; i <= n;) {
		if(j == -1 || s[i] == s[j])
			kmp[++i] = ++j;
		else
			j = kmp[j];
	}
}

void KMP(string s1, string s2) {
	int la = (int)s1.size();
	int lb = (int)s2.size();
	for(int i = 0, j = 0; i < la;) {
		if(j == -1 || s2[j] == s1[i]) {
			i++;
			j++;
		} else {
			j = kmp[j];
		}
		if(j == lb) {
			cout << i - lb + 1 << '\n';
			j = kmp[j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s1 >> s2;
	getnext(s2);
	KMP(s1, s2);
	int len = (int)s2.size();
	for(int i = 1; i <= len; i++) {
		cout << kmp[i] << " ";
	}

	return 0;
}