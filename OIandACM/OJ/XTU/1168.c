#include <stdio.h>

int main()
{
	int n, m;
	int f[1111];
	while(~scanf("%d%d", &n, &m)){
		f[1] = m;
		f[2] = m * (m - 1) % 1000003;
		f[3] = f[2] * (m - 2) % 1000003;
		for(int i = 4; i <= n; i++)
			f[i] = (f[i - 1] * (m - 2) % 1000003 + f[i - 2] * (m - 1) % 1000003) % 1000003;
		printf("%d\n", f[n]);
	}
	return 0;
}