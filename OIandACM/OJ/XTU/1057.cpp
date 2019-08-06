#include <bits/stdc++.h>

bool is[13333];
int prime[13333];
int top;

int main()
{
	int x;
	int ans;
	//scanf("%d", &n);
	memset(is, true, sizeof(is));
	is[0] = is[1] = false;
	for(int i = 2; i <= 13333; i++){
		if(is[i])
			prime[++top] = i;
		for(int j = 0; j < top && i * prime[j] < 123333333; j++){
			is[i * prime[j]] = false;
			if(!(i % prime[j]))
				break;
		}
	}
	top = 0;

	while(scanf("%d", &x) == 1){
		for(int i = prime[++top]; x != 1;){
			//if(is_prime(i)){
			ans = 0;
			while(x % i == 0){
				++ans;
				x /= i;
			}
			if(ans){
				printf("%d", i);
				if(ans != 1)
					printf("^%d", ans);
				if(x != 1)
					printf("*");
			}
		}
		putchar('\n');
	}
	return 0;
}