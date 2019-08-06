#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	int a[2333];
	int cnt, ans;// flag, fang;
	char f[2333];

	while(cin >> n){
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		cnt = ans = 0;
		//fang = 1;
		memset(f, 0, sizeof(f));

		while(cnt != n){
			for(int i = 1; i <= n; i++)
				if(f[i] == 0)
					if(cnt >= a[i]){
						cnt++;
						f[i]++;
					}
			if(cnt == n)
				break;
			ans++;
			for(int i = n; i >= 1; i--)
				if(f[i] == 0)
					if(cnt >= a[i]){
						cnt++;
						f[i]++;
					}
			if(cnt == n)
				break;
			ans++;
		}

		cout << ans << endl;
	}
	return 0;
}