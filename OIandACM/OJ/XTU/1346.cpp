#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, x, v, ll, n;
	double ans;
	bool flag;
	cin >> t;

	while(t--){
		cin >> n >> ll;
		ans = 0;
		flag = true;
		for(int i = 0; i < n; ++i){
			cin >> x >> v;
			if(v == 0)
				flag = false;
			if(v > 0)
				ans = max(ans, (ll - x) / (double)v);
			if(v < 0)
				ans = max(ans, x / (-(double)v));
		}
		if(flag)
			printf("%.1f\n", ans);
		else
			cout << "Impossible\n";
	}
	return 0;
}