#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	int a[2333];
	int cnt, ans, flag;
	char f[2333];

	while(cin >> n){
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		cnt = ans = 0;
		flag = 1;
		memset(f, 0, sizeof(f));

		while(flag){
			for(int i = 1; i <= n; i++)
				if(f[i] == 0){
					if(cnt >= a[i]){
						cnt++;
						f[i]++;
					}
					flag = 1;
				}else{
					flag = 0;
				}
			ans++;
		}

		cout << ans - 1 << endl;
	}
	return 0;
}