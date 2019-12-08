#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

// const double pi = acos(-1.0);
const double pi = 3.14159265358979323846;
int s[10009];
const double eps = 1e-6;

int main()
{
	int t;
	scanf("%d", &t);

	while(t--){
		int n, f;
		int r;
		scanf("%d%d", &n, &f);
		for(int i = 1; i <= n; i++){
			scanf("%d", &r);
			// s[i] = pi * r * r;
			s[i] = r * r;
		}
		sort(s + 1, s + n + 1);
		// for(int i = 1; i <= n; i++){printf("%d ", s[i]);}
		double ll = 0.0;
		double ri = s[n];
		double mid;
		while(ri - ll > eps){
			mid = (ll + ri) / 2.0;
			bool flag = false;
			int sum = 0;
			for(int i = 1; i <= n; i++){
				sum += floor(s[i]/mid);
				if(sum >= f + 1){
					flag = true;
					break;
				}
			}
			if(flag){
				ll = mid + eps;
			}else{
				ri = mid - eps;
			}
		}
		printf("%.4lf\n", mid * pi);
		// cout << mid << endl;
	}
	return 0;
}