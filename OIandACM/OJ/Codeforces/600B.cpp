#include <bits/stdc++.h>
using namespace std;

int a[233333], b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < m; i++){
    	cin >> b;
	cout << upper_bound(a, a+n, b) - a << " ";
    }
    //sort(b, b + n);
    return 0;
}