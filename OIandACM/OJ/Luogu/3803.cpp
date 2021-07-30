#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 998244353;

ll qpow(ll x, ll t = mod - 2) {
	ll ret = 1;
	while(t) {
		if(t & 1)
			ret = ret * x % mod;
		x = x * x % mod;
		t >>= 1;
	}
	return ret;
}

namespace NTT {
int	 rev[5000050], N; // 5e6
ll	 w[5000050], I;
void init(int n) {
	for(N = 1; N <= n; N <<= 1)
		;
	I = qpow(N);

	rev[0] = 0, rev[1] = N >> 1;
	for(int i = 2; i < N; ++i)
		rev[i] = rev[i >> 1] >> 1 | rev[i & 1];

	w[0] = 1, w[1] = qpow(3, (mod - 1) / N);
	for(int i = 2; i < N; ++i)
		w[i] = w[i - 1] * w[1] % mod;
}

void DFT(ll *A) {
	for(int i = 0; i < N; ++i)
		if(i < rev[i])
			swap(A[i], A[rev[i]]);

	for(int len = 2; len <= N; len <<= 1) {
		int m = len >> 1;
		for(ll *p = A; p != A + N; p += len)
			for(int i = 0; i < m; ++i) {
				ll u = p[i], v = p[i + m] * w[N / len * i] % mod;
				p[i]	 = (u + v) % mod;
				p[i + m] = (u - v + mod) % mod;
			}
	}
}

void IDFT(ll *A) {
	DFT(A);
	reverse(A + 1, A + N);
	for(int i = 0; i < N; ++i)
		A[i] = A[i] * I % mod;
}
} // namespace NTT

ll A[5000050], B[5000050];

int main() {
	int n, m;
    // freopen("../in.txt", "r", stdin);
    // freopen("../out.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; ++i)
		scanf("%lld", &A[i]);
	for(int i = 0; i <= m; ++i)
		scanf("%lld", &B[i]);

	NTT::init(n + m + 2);
	NTT::DFT(A);
	NTT::DFT(B);
	for(int i = 0; i < NTT::N; ++i)
		A[i] = A[i] * B[i] % mod;
	NTT::IDFT(A);

	for(int i = 0; i <= n + m; ++i) {
		printf("%lld ", A[i]);
	}
	return 0;
}