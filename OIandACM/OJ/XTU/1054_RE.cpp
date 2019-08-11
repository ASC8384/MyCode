#include <bits/stdc++.h>
using namespace std;

inline int init(void){
	char c;
	int x;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, aa[1002];
	set<__int64> a;
	set<__int64>::iterator i;
	int ans;
	cin >> n;

	while(n != 0){
		a.clear();
		ans = 0;
		for(int i = 0; i < n; i++)
			aa[i] = init();
		a.insert(aa, aa + n);
		for(i = a.begin(); i != a.end();)
			if(a.find(*i * *i) != a.end()){
				a.erase(*i * *i);
				a.erase(*i);
				ans++;
				i = a.begin();
			}else{
				i++;
			}
		cout << ans << endl;
		n = init();
	}
	return 0;
}