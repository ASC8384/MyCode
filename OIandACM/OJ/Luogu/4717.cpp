/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-08-02 17:44:01
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 1 << 18 | 1;
// const ll  mod  = 998244353;
// const int n	   = 1 << 18;

// int n, m;
int A[size], B[size], a[size], b[size];
struct FWT {
	const ll P	  = 998244353;
	const ll inv2 = (P + 1) >> 1;

	void add(int &x, int y) {
		(x += y) >= P && (x -= P);
	}
	void sub(int &x, int y) {
		(x -= y) < 0 && (x += P);
	}
	int extend(int n) {
		int N = 1;
		while(N < n)
			N <<= 1;
		return N;
	}
	void FWTor(vector<int> &a, bool rev) {
		int n = a.size();
		for(int l = 2, m = 1; l <= n; l <<= 1, m <<= 1) {
			for(int j = 0; j < n; j += l)
				for(int i = 0; i < m; i++) {
					if(!rev)
						add(a[i + j + m], a[i + j]);
					else
						sub(a[i + j + m], a[i + j]);
				}
		}
	}
	void FWTand(vector<int> &a, bool rev) {
		int n = a.size();
		for(int l = 2, m = 1; l <= n; l <<= 1, m <<= 1) {
			for(int j = 0; j < n; j += l)
				for(int i = 0; i < m; i++) {
					if(!rev)
						add(a[i + j], a[i + j + m]);
					else
						sub(a[i + j], a[i + j + m]);
				}
		}
	}
	void FWTxor(vector<int> &a, bool rev) {
		int n = a.size(), inv2 = (P + 1) >> 1;
		for(int l = 2, m = 1; l <= n; l <<= 1, m <<= 1) {
			for(int j = 0; j < n; j += l)
				for(int i = 0; i < m; i++) {
					int x = a[i + j], y = a[i + j + m];
					if(!rev) {
						a[i + j]	 = (x + y) % P;
						a[i + j + m] = (x - y + P) % P;
					} else {
						a[i + j]	 = 1LL * (x + y) * inv2 % P;
						a[i + j + m] = 1LL * (x - y + P) * inv2 % P;
					}
				}
		}
	}
	vector<int> Or(vector<int> a1, vector<int> a2) {
		int n = max(a1.size(), a2.size()), N = extend(n);
		a1.resize(N), FWTor(a1, false);
		a2.resize(N), FWTor(a2, false);
		vector<int> A(N);
		for(int i = 0; i < N; i++)
			A[i] = 1LL * a1[i] * a2[i] % P;
		FWTor(A, true);
		return A;
	}
	vector<int> And(vector<int> a1, vector<int> a2) {
		int n = max(a1.size(), a2.size()), N = extend(n);
		a1.resize(N), FWTand(a1, false);
		a2.resize(N), FWTand(a2, false);
		vector<int> A(N);
		for(int i = 0; i < N; i++)
			A[i] = 1LL * a1[i] * a2[i] % P;
		FWTand(A, true);
		return A;
	}
	vector<int> Xor(vector<int> a1, vector<int> a2) {
		int n = max(a1.size(), a2.size()), N = extend(n);
		a1.resize(N), FWTxor(a1, false);
		a2.resize(N), FWTxor(a2, false);
		vector<int> A(N);
		for(int i = 0; i < N; i++)
			A[i] = 1LL * a1[i] * a2[i] % P;
		FWTxor(A, true);
		return A;
	}
} fwt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	// n <<= 1;
	n = (1 << n);
	vector<int> a1(n), a2(n);
	for(int i = 0; i < n; i++)
		cin >> a1[i];
	for(int i = 0; i < n; i++)
		cin >> a2[i];
	vector<int> A;
	A = fwt.Or(a1, a2);
	for(int i = 0; i < n; i++) {
		cout << A[i] << ' ';
	}
	cout << '\n';
	A = fwt.And(a1, a2);
	for(int i = 0; i < n; i++) {
		cout << A[i] << ' ';
	}
	cout << '\n';
	A = fwt.Xor(a1, a2);
	for(int i = 0; i < n; i++) {
		cout << A[i] << ' ';
	}
	cout << '\n';

	return 0;
}