#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

deque<int> a[22];
int n, ans;

void dfs(int cnt){
	if(cnt == n){
		int tmp = 0;
		int sum;
		for(int i = 0; i < n; ++i){
			sum = 0;
			for(int j = 0; j < n; ++j){
				sum += a[j][i];
			}
			tmp = max(sum, tmp);
		}
		ans = min(ans, tmp);
	}else{
		for(int i = 0; i < n; ++i){
			a[cnt].push_front(a[cnt].back());
			a[cnt].pop_back();
			dfs(cnt + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n && n != -1){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				int tmp;
				cin >> tmp;
				a[i].push_back(tmp);
			}
		}
		ans = 0x7fffffff;
		dfs(0);
		cout << ans << endl;
	}
	return 0;
}