#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace::std;
typedef long long ll;

int n, k;

ll qpow(ll n, ll t){
	ll ret = 1;
	while(t){
		if(t & 1)
			ret = ret * n % k;
		n = n * n % k;
		t >>= 1;
	}
	return ret;
}

bool vis[55555];
int tot = 0;
const int N = 55555;
int prime[N];

void isprime(){
    memset(vis,0,sizeof(vis));
    vis[1] = 1;
    for (int i = 2; i < N; i++){
        if (!vis[i]) {
			prime[++tot]=i;
		}else{
            for (int j = 1; j <= tot && prime[j] * i < N; j++){
                vis[prime[j] * i] = 1;
                if(i % prime[j] == 0)
					break;
            }
        }
    }
}

int phi(int n){
    int ret = n;
    for (int i = 1; prime[i] * prime[i] <= (ll)n; i++){
        if (n % prime[i] == 0){
            ret = ret - ret / prime[i];
            while (n % prime[i] == 0)
				n /= prime[i];
        }
    }
    if (n != 1)
		ret = ret - ret / n;
    return ret % k;
}

int main()
{
	isprime();
	// cin.tie(0);
	// cout.tie(0);
	int t;
	// cin >> t;
	scanf("%d", &t);
	while (t--) {
		// cin >> n >> k;
		scanf("%d%d", &n, &k);
		int ans = 0;
		for(int i = 1; i * i <= n; i++) {
			if(n % i)
				continue;
			ans += phi(i) * qpow(n, n / i - 1);
			ans %= k;
			if(i * i != n)
				ans += phi(n / i) * qpow(n, i - 1);
			ans %= k;
		}
		// cout << ans << '\n';
		printf("%d\n", ans);
	}
	return 0;
}
