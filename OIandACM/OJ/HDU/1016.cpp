#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int  n;
int  a[23];
bool is[23];

bool isp(int x) {
	if(x <= 3)
		return true;
	if(x % 2 == 0)
		return false;
	int t = sqrt(x);
	for(int i = 3; i <= t; i += 2)
		if(x % i == 0)
			return false;
	return true;
}

void dfs(int sum) {
	if(sum == n && isp(a[0] + a[n - 1])) {
		for(int i = 0; i < n - 1; i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n - 1]);
	} else {
		for(int i = 2; i <= n; i++) {
			if(!is[i] && isp(i + a[sum - 1])) {
				is[i]  = true;
				a[sum] = i;
				dfs(sum + 1);
				is[i] = false;
			}
		}
	}
}

int main() {
	int cnt = 0;
	while(~scanf("%d", &n)) {
		printf("Case %d:\n", ++cnt);
		memset(a, 0, sizeof(a));
		memset(is, 0, sizeof(is));
		a[0] = 1;
		dfs(1);

		putchar('\n');
	}
	return 0;
}