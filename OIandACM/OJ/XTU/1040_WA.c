#include <stdio.h>
#include <string.h>

int main()
{
	unsigned int n, k;
	int maxl, cnt;
	char a[33][33], b[33][33];
	int len[33];
	register unsigned int i, j;
	scanf("%d\n", &n);

	while(n--){
		scanf("%d\n", &k);
		for(i = 0; i < k; i++)
			//scanf("%[^\n]", a[i]);
			gets(a[i]);
		for(i = 0; i < k; i++)
			gets(b[i]);
			//scanf("%[^\n]", b[i]);
		maxl = cnt = 0;
		memset(len, 0, sizeof(int)*33);
		for(i = 0; i < k; i++){
			for(j = 0; j < strlen(a[i]); j++)
				if(a[i][j] == 'X')
					len[i]++;
			for(j = 0; j < strlen(b[i]); j++)
				if(b[i][j] == 'X')
					len[i]++;
			if(maxl < len[i])
				maxl = len[i];
			cnt += len[i];
		}
		printf("%d\n", maxl*k -cnt);
	}
	return 0;
}