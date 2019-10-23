#include <cstdio>
using namespace std;

int san[22][22];
int ans[22];
bool f[22], flag;
int n, num;

void dfs(int pos, int sum){
	if(sum > num || flag)
		return;
	if(pos == n+1 && sum == num){
		flag = true;
		for(int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
	}else{
		for(int i = 1; i <= n; i++){
			if(!f[i]){
				//ans[++top] = i;
				ans[pos] = i;
				f[i] = true;
				dfs(pos + 1, sum + i * san[n][pos]);
				f[i] = false;
			}
		}
	}
}

int main()
{
	for(int i = 1; i < 13; i++)
		san[i][1] = san[i][i] = 1;
	for(int i = 3; i < 13; i++)
		for(int j = 2; j < 13; j++)
			san[i][j] = san[i - 1][j] + san[i - 1][j - 1];

	scanf("%d%d", &n, &num);
	dfs(1, 0);
	return 0;
}
