#include <bits/stdc++.h>
using namespace std;

unsigned long long A[490009];
unsigned long long B[490009];

int top;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int		  n;
	long long x;
	cin >> n >> x;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
		B[i] = B[i - 1] + (1 + A[i]) * A[i] / 2;
		A[i] += A[i - 1];
	}
	for(int i = 1; i <= n; i++) {
		A[i + n] = A[i] + A[n];
		B[i + n] = B[i] + B[n];
	}

	long long ans = 0;
	long long ll = 1, rr = 1;

	while(!(A[rr] - A[ll - 1] < x && rr == 2 * n)) {
		if(A[rr] - A[ll - 1] < x) {
			rr++;
		} else {
			long long ysbc = B[rr] - B[ll];
			long long tmuu = x - A[rr] + A[ll];
			long long uhyt = A[ll] - A[ll - 1];

			ll++;
			ysbc = ysbc + (uhyt * 2 - tmuu + 1) * tmuu / 2;
			ans	 = max(ysbc, ans);
		}
	}
	cout << ans << endl;

	return 0;
}