#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int			n;
int			ans;
vector<int> shu;
int			arr[233333];

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	while(n = init()) {
		ans = 0;
		shu.clear();
		for(int i = 0; i < n; i++) {
			// scanf("%d", arr + i);
			// cin >> arr[i];
            arr[i] = init();
			ans += shu.end() - upper_bound(shu.begin(), shu.end(), arr[i]);
			shu.insert(upper_bound(shu.begin(), shu.end(), arr[i]), arr[i]);
			//cout << shu.end() - upper_bound(shu.begin(), shu.end(), arr[i]) << endl;
		}
		printf("%d\n", ans);
		// cout << ans << '\n';
	}
	return 0;
}