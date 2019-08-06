#include <bits/stdc++.h>

bool prime[429496];

int main()
{
	unsigned int n;
	scanf("%d", &n);
	
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(register __int64 i = 3; i < 429496; i += 2){
		if(prime[i])
			for(register __int64 j = i << 1; j <= 429496; j += i)
				prime[j] = false;
	}
	while(n != 0){
		if(n <= 429496){
			if((prime[n] && (n & 1)) || n == 2)
				printf("Yes\n");
			else
				printf("No\n");
		}else{
			if(n % 6 != 1 && n % 6 != 5){
				printf("No\n");
				continue;
			}
			for(__int64 i = 5; i * i <= n; i += 6)
				if(n % i == 0 || n % (i+2) == 2){
					printf("No\n");
					continue;
				}
			printf("Yes\n");
		}
		scanf("%d", &n);
	}
}