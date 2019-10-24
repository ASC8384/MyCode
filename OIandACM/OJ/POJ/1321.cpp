#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

char mapp[10][10];
bool viss[10];
int f[10][10];
int ans, n, k;

void dfs(int r, int cnt){
	if(r > n)
		return;
	if(cnt == k){
		ans++;
	}else{
		for(int i = 0; i < n; i++){
			if(mapp[r][i] == '#' && !viss[i]){
				viss[i] = true;
				dfs(r + 1, cnt + 1);
				viss[i] = false;
			}
		}
		dfs(r + 1, cnt);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> k && n != -1 && k != -1){
		for(int i = 0; i < n; ++i){
			cin >> mapp[i];
		}
		ans = 0;
		memset(viss, 0, sizeof(viss));
		dfs(0, 0);
		cout << ans << endl;
	}

	return 0;
}