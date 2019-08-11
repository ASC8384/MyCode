#include <bits/stdc++.h>
using namespace std;

int top = 1, n;
__int64 ans[8877699];
bool is[11];

void dfs(__int64 x, int n, int wei){
	if(n == wei){
		ans[++top] = x;
	}else{
		for(int i = 0; i < 10; i++){
			if(is[i])
				continue;
			if(x || i){
				is[i] = true;
				dfs(x * 10 + i, n + 1, wei);
				is[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	for(int i = 1; i <= 10; i++){
		memset(is, 0, sizeof(is));
		dfs(0, 0, i);
	}

	while(cin >> n){
		cout << ans[n] << endl;
	}
	return 0;
}