/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j < i; j++)
				cout << j << " " << i << '\n';
		}
	}

	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowBit(x) ((x) & (-x))
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define per(i, a, n) for(ll i = n; i >= a; i--)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((ll)(x).size())
typedef vector<ll>	 VI;
typedef pair<ll, ll> PII;
const ll			 mod = 1e9 + 7;
const ll			 N	 = 2e5 + 6;
ll					 gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll					 powmod(ll a, ll b) {
	  ll ans = 1;
	  a %= mod;
	  while(b > 0) {
		  if(b & 1)
			  ans = ans * a % mod;
		  a = a * a % mod;
		  b >>= 1;
	  }
	  return ans % mod;
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

ll t, n, ans;
ll f[333];

map<int, int> mp;

vector<pair<int, int>> v, v1;

int main() {
	// t = readn();
	// while(t--) {
	FILE *fp = fopen("5675I.txt", "w");
	FILE *fa = fopen("5675I-ans.txt", "w");
	for(int t = 1; t <= 300; t++) {
		srand(time(NULL));
		// n = readn();
		n = t;
		v.clear();
		for(ll i = n - 1; i >= 1; i--)
			for(ll j = i + 1; j <= n; j++)
				v.pb({i, j});
		v1	= v;
		ans = 0x7ffffffffffffff;
		for(ll i = 1; i < 54321; i++) {
			random_shuffle(v.begin(), v.end());
			ll tmp = 0;
			for(ll j = 1; j <= n; j++) {
				for(ll x = v.size() - 1; x >= 0; x--) {
					if(v[x].fi == j || v[x].se == j) {
						tmp += (x + 1);
						break;
					}
				}
				for(ll x = 0; x < v.size(); x++) {
					if(v[x].fi == j || v[x].se == j) {
						tmp -= (x);
						break;
					}
				}
			}
			if(ans > tmp) {
				v1	= v;
				ans = tmp;
			}
		} //  random_shuffle(v.begin(), v.end());
		//  random_shuffle(v.begin(), v.end());
		fprintf(fp, "{");
		for(ll i = 0; i < v1.size(); i++)
			fprintf(fp, "%lld,%lld,", v1[i].fi, v1[i].se);
		fprintf(fp, "},");
		f[t] = ans;
		fprintf(fa, "%d:%lld\n", t, f[t]);
		printf("%d:%lld\n", t, f[t]);
	}
	// for(int i = 1; i <= 300; i++) {
	// }
}
