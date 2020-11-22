#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		bool flg = true;
		ll	 d, k;
		cin >> d >> k;
		d *= d;
		k *= k;
		ll x = sqrt((d) / (k * 2));
		ll y = sqrt((d - k * x * x) / (k));
		if((x + y) & 1)
			cout << "Ashish\n";
		else
			cout << "Utkarsh\n";
	}

	return 0;
}