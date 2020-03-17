#include <bits/stdc++.h>
using namespace std;
#define io                                                                                         \
	ios_base::sync_with_stdio(false);                                                              \
	cin.tie(NULL);                                                                                 \
	cout.tie(NULL)
#define ll long long
#define ull unsigned long long
#define mod 998244353
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fo(i, a, b) for(ll i = a; i < b; i++)
#define pi 3.141592653589793238
int subseq(int arr[], int n) {
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	fo(i, 0, n) dp[i][i] = 1;
	int i, j, c;
	for(c = 2; c <= n; c++) {
		for(i = 0; i < n - c + 1; i++) {
			j = i + c - 1;
			if(arr[i] == arr[j] && c == 2)
				dp[i][j] = 2;
			else if(arr[i] == arr[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
		}
	}

	return dp[0][n - 1];
}
int main() {
	io;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		fo(i, 0, n) cin >> arr[i];
		int l = subseq(arr, n);
		if(l >= 3)
			cout << "YES";
		else
			cout << "NO";
		if(t > 0)
			cout << endl;
	}
	return 0;
}
