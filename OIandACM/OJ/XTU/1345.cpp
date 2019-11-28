#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000000;
bool pri[maxn];
int ans[1000009][12];

int main(int argc, char* argv[])
{
	pri[0] = pri[1] = true;
	int t = sqrt(maxn);
	for(int i = 4; i < maxn; i += 2)
		pri[i] = true;
	for(int i = 3; i < t; i += 2){
		if(!pri[i]){
			for(int j = (i << 1); j < maxn; j += i){
				pri[j] = true;
			}
		}
	}
	string a = " 2";
	// cout << a << endl;
	for(int i = 3; i < maxn && a.size() < 1000009; i += 2)
		if(!pri[i]){
			char s[23];
			sprintf(s, "%d", i);
			a += s;
			// a += to_string(i);
		}
	//int ll = a.size();
	// cout << a.substr(0, 100);
	for(int i = 1; i <= 1000005; i++){
		for(int j = 0; j <= 9; j++){
			ans[i][j] += ans[i-1][j];
		}
		ans[i][a[i] - '0']++;
	}

	cin >> t;
	while(t--){
		int ll, rr, d;
		cin >> ll >> rr >> d;
		cout << ans[rr][d] - ans[ll-1][d] << endl;
	}
	return 0;
}