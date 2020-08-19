/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-19 20:47:05
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 295 + 9;
const ll  mod  = 1e9 + 7;

string s[size][6];

bool is(string s1, string s2, string s3) {
	if(s1 == s2 && s1 != s3 && s1 != "*" && s3 != "*")
		return false;
	if(s1 == s3 && s1 != s2 && s1 != "*" && s2 != "*")
		return false;
	if(s2 == s3 && s1 != s2 && s1 != "*" && s2 != "*")
		return false;
	return true;
}

bool ok(int x, int y, int z) {
	for(int i = 1; i <= 4; i++)
		if(!is(s[x][i], s[y][i], s[z][i]))
			return false;
	return true;
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);

	int T;
	// cin >> T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		// cout << "Case #" << t << ":";
		printf("Case #%d: ", t);
		int n;
		cin >> n;
		bool ff = true;
		for(int i = 1; i <= n; i++) {
			// s[i].clear();
			s[i][1].clear();
			s[i][2].clear();
			s[i][3].clear();
			s[i][4].clear();
			string ss;
			cin >> ss;
			int len = ss.size();
			int cnt = 0;
			for(int j = 0; j < len; j++) {
				if(ss[j] == '[') {
					cnt++;
				} else if(ss[j] == ']') {
				} else {
					s[i][cnt] += ss[j];
				}
			}
			// cout << s[i][1] << " " << s[i][2] << " " << s[i][3] << " " << s[i][4] << endl;
		}
		const int si = 21; //niubi
		for(int i = 1; i <= min(n, si); i++)
			for(int j = i + 1; j <= min(n, si); j++)
				for(int k = j + 1; k <= min(n, si); k++)
					if(ok(i, j, k)) {
						printf("%d %d %d\n", i, j, k);
						ff = false;
						goto end;
					}
	end:
		if(ff)
			printf("-1\n");
	}

	return 0;
}