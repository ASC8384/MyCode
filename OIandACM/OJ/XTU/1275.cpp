#include <bits/stdc++.h>
using namespace std;

char a[9][233];
int ans[6][88], cnt, top[8];

int main()
{
	ios::sync_with_stdio(false);
	int k, n, t, s, e;
	string d;
	//char d[9];

	int st, ed;
	string tmp[7] = {"", "Mon", "Tue", "Wen", "Thur", "Fri"};
	cin >> k;

	while(k--){
		cin >> n >> t;
		cnt = 0;
		memset(a, 0, sizeof(a));
		memset(ans, 0, sizeof(ans));
		memset(top, 0, sizeof(top));
		for(int i = 0; i < n; i++){
			cin >> d >> s >> e;
				if(d == "Mon")
					for(int j = s; j <= e; j++)
						a[1][j] = 1;
				if(d == "Tue")
					for(int j = s; j <= e; j++)
						a[2][j] = 1;
				if(d == "Wen")
					for(int j = s; j <= e; j++)
						a[3][j] = 1;
				if(d == "Thur")
					for(int j = s; j <= e; j++)
						a[4][j] = 1;
				if(d == "Fri")
					for(int j = s; j <= e; j++)
						a[5][j] = 1;
		}
		for(int i = 1; i <= 5; i++){
			for(st = 1; st <= 11; st++){
				for(ed = st; ed <= st + t - 1; ed++)
					if(a[i][ed] == 0 &&
						((st <= 4 && ed <= 4) || 
						(4 < st && st <= 8 && ed <= 8) || 
						(9 <= st && ed <= 11)))
						continue;
					else
						break;
				if(ed == st + t){
					ans[i][++top[i]] = st;
					ans[i][++top[i]] = ed - 1;
				}
			}
			cnt += (top[i] >> 1);
		}
		cout << cnt << endl;
		for(int i = 1; i <= 5; i++)
			for(int j = 1; j <= top[i]; j += 2)
				cout << tmp[i] << " " << ans[i][j] << " " << ans[i][j+1] << endl;
				//printf("%s %d %d\n", tmp[i], ans[i][j], ans[i][j+1]);
	}
	return 0;
}