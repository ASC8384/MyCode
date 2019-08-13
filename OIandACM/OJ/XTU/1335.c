// https://www.luogu.org/recori/2481782
// 2 years ago,i can't unierstani
#include <stdio.h>  
#include <math.h>
#include <ctype.h>

int r, ans;

int gcd(int a, int b){
	return a % b == 0 ? b : gcd(b, a % b);
}

char is(int x, double y){
	if(y == floor(y)){
		int tmp = (int)floor(y);
		if(gcd(tmp * tmp, x * x) == 1 && tmp * tmp != x * x)
			return 1;
	}
	return 0;
}

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main()
{
	// scanf("%lli", &r);
	int t = init();

	while(t--){
		r = init();
		ans = 0;
		register int i, k;
		for(i = 1; i <= (int)sqrt(2 * r); i++){
			if((2 * r) % i == 0){
				for(k = 1; k <= (int)sqrt(r / i); k++){
					double tmp = sqrt(((2 * r) / i) - k * k);
					if(is(k, tmp))
						ans++;
				}
				if(i != (2 * r) / i){
					for(k = 1; k <= (int)sqrt(i / 2); k++){
						double tmp = sqrt(i - k * k);
						if(is(k, tmp))
							ans++;
					}
				}
			}
		}
		printf("%d\n", ans * 4 + 4);
	}
	return 0;
}