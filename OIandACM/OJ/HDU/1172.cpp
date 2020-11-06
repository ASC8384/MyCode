#include <bits/stdc++.h>
#include <unordered_map>
using namespace::std;

const int size = 555;
int a[size], b[size], c[size];
int n;

bool is(int x){
	bool flg = true;

	for(int i = 1; flg && i <= n; i++){
		unordered_map<int, int> m1, m2;
		int bb = 0;
		int cc = 0;
		m1[a[i] % 10]++;
		m1[a[i] / 10 % 10]++;
		m1[a[i] / 100 % 10]++;
		m1[a[i] / 1000 % 10]++;
		m2[x % 10]++;
		m2[x / 10 % 10]++;
		m2[x / 100 % 10]++;
		m2[x / 1000 % 10]++;
		for(int j = 0; j <= 9; j++)
			bb += min(m1[j], m2[j]);
		if(a[i] % 10 == x % 10)
			cc++;
		if(a[i] / 10 % 10 == x / 10 % 10)
			cc++;
		if(a[i] / 100 % 10 == x / 100 % 10)
			cc++;
		if(a[i] / 1000 % 10 == x / 1000 % 10)
			cc++;
		flg = (cc == c[i]) && (bb == b[i]);
	}

	return flg;
}

int main()
{
	while(cin >> n && n){
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		bool flg = false;
		int ans = -1;
		for(int i = 0; i <= 9999; i++){
			bool now = is(i);
			if(now && flg){
				flg = false;
				break;
			}
			if(now && !flg)
				ans = i, flg = true;
		}
		if(flg){
			cout << ans << '\n';
		}else{
			cout << "Not sure" << '\n';
		}
	}
	return 0;
}
