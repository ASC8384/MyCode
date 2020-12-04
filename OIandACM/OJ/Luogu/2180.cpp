#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n, m, k;
	while(scanf("%lld%lld%lld", &n, &m, &k) != EOF){
		if(n > m)
			swap(n, m);
		int len = min(n, k);
		ll ans = 0;
		for(int i = 1; i <= len; i++){
			int x = k / i;
			int y = k % i;
			if(!y && x > m)
                continue;
            if(y && x >= m)
                continue;
			ans = max(ans, (ll)(x*(x-1)/2*i*(i-1)/2 + y*(y-1)/2*x));
		}
        printf("%lld\n", ans);
	}
	return 0;
}