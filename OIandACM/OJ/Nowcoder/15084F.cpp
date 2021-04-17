/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2021-04-17 12:52:19
*/
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

    int n, s;
    cin >> n >> s;
    int a;
    cin >> a;
    int maxx = a;
    int minn = a;
    for(int i = 2; i <= n; i++){
        cin >> a;
        maxx = max(a, maxx);
        minn = min(minn, a);
    }
    if(minn >= s)
		cout << (maxx - s) << '\n';
	else if(maxx <= s)
		cout << (s - minn) << '\n';
	else
		cout << (min(maxx - s, s - minn) * 2 + max(maxx - s, s - minn)) << '\n';

    return 0;
}