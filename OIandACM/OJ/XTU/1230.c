#include <stdio.h>

int main()
{
	int n, m, t;
	char s[23];

	while(scanf("%d%d%s", &n, &m, s) == 3){
		if(s[0] == 'A'){
			t = n - m;
			if((t & 1) || m > n || n == 0 || m == 0)
				printf("Impossible\n");
			else
				printf("%d:%d\n", (t >> 1) + m, (t >> 1));
		}else if(s[0] == 'B'){
			t = n - m;
			if((t & 1) || m > n || n == 0 || m == 0)
				printf("Impossible\n");
			else
				printf("%d:%d\n", (t >> 1), (t >> 1) + m);
		}else{
			if(m || (n & 1))
				printf("Impossible\n");
			else
				printf("%d:%d\n", n >> 1, n >> 1);
		}
	}
}