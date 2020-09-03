#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowBit(x) ((x) & (-x))
#define rep(i, a, n) for(ll i = a; i <= n; i++)
#define per(i, a, n) for(ll i = n; i >= a; i--)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((ll)(x).size())
typedef vector<ll>	 VI;
typedef pair<ll, ll> PII;
const ll			 mod = 1e9 + 7;
const ll			 N	 = 1e5 + 6;
ll					 gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll					 powmod(ll a, ll b) {
	  ll ans = 1;
	  while(b > 0) {
		  if(b & 1)
			  ans = ans * a % mod;
		  a = a * a % mod;
		  b >>= 1;
	  }
	  return ans;
}
ll readn() {
	ll	 sum = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0') {
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		sum = sum * 10 + (ch - '0');
		ch	= getchar();
	}
	return sum * f;
}

int low[2333], a[2333], p[2333], n, ans, res = 0;

int binary_search(int *a, int R, int x) {
	int L = 1, mid;
	while(L <= R) {
		mid = (L + R) >> 1;
		if(a[mid] <= x)
			L = mid + 1;
		else
			R = mid - 1;
	}
	return L;
}

void get() {
	for(int i = 1; i <= n; i++)
		low[i] = 99999999;
	low[1] = a[1];
	ans	   = 1;
	for(int i = 2; i <= n; i++) {
		if(a[i] > low[ans])
			low[++ans] = a[i];
		else
			low[binary_search(low, ans, a[i])] = a[i];
	}
	res = max(res, ans);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int op = j + i - 1;
			if(op > n)
				op -= n;
			a[j] = p[op];
			//cout<<a[j]<<' ';
		}
		get();
	}
	cout << n - res << endl;
}
