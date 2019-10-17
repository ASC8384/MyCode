#include <bits/stdc++.h>
using namespace std;

int ans, n;
char mapp[22][22];

bool is(int r, int c){
	for(int i = r; i >= 0; i--)
		if(mapp[i][c] == 'X')
			break;//
		else if(mapp[i][c] == 'B')
			return false;
	for(int i = c; i >= 0; i--)
		if(mapp[r][i] == 'X')
			return true;
		else if(mapp[r][i] == 'B')
			return false;
	return true;
}

void dfs(int cnt, int pos){
	if(pos == n*n){
		ans = max(ans, cnt);
	}else{
		int r = pos / n;
		int c = pos % n;
		if(mapp[r][c] == '.'){
			if(is(r, c)){
				mapp[r][c] = 'B';
				dfs(cnt+1, pos+1);
				mapp[r][c] = '.';
			}
		}
		dfs(cnt, pos+1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n, n){
		for(int i = 0; i < n; ++i){
			cin >> mapp[i];
		}
		ans = 0;
		dfs(0, 0);
		cout << ans << endl;
	}
	return 0;
}
