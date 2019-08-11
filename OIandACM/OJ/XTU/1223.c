#include <stdio.h>

int main()
{
	int k;
	int n, m, t;
	scanf("%d", &k);

	while(k--){
		scanf("%d", &m);
		if((m & 1) == 0 || m % 5 == 0)
			printf("0\n");
		else{
			n = 1;
			t = m;
			while(t--){
				n = n % m;
				if(n == 0)
					break;
				n = 10 * n + 1;
			}
			if(n)
				printf("0\n");
			else
				printf("%d\n", m - t);
		}
	}
	return 0;
}