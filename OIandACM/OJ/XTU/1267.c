#include <stdio.h>

int a[23][23];

void swap(int *x, int *y){
	int t = *x;
	*x = *y;
	*y = t;
}

int main()
{
	int x, y, i, j, n, m;
	char s[23];

	while(scanf("%s", s) == 1){
		if(s[0] == 'I'){
			scanf("%d%d", &n, &m);
			for(i = 1; i <= n; i++)
				for(j = 1; j <= m; j++)
					a[i][j] = m*i - m + j;
		}else if(s[0] == 'S'){
			scanf("%d%d", &x, &y);
			if(s[1] == 'R'){
				for(i = 1; i <= m; i++){
					swap(&a[x][i], &a[y][i]);
				}
			}else{
				for(i = 1; i <= n; i++){
					swap(&a[i][x], &a[i][y]);
				}
			}
		}else if(s[0] == 'T'){
			int t, r;
			if(n > m){
				t = n;
				r = m;
			}else{
				t = m;
				r = n;
			}
			for(i = 1; i <= r; i++)
				for(j = i; j <= t; j++)
					swap(&a[i][j], &a[j][i]);
			swap(&n, &m);
		}else if(s[0] == 'F'){
			if(s[1] == 'R'){
				for(i = 1; i <= n >> 1; i++)
					for(j = 1; j <= m; j++)
						swap(&a[i][j], &a[n - i + 1][j]);
			}else{
				for(i = 1; i <= m >> 1; i++)
					for(j = 1; j <= n; j++)
						swap(&a[j][i], &a[j][m - i + 1]);
			}
		}else{
			for(i = 1; i <= n; i++){
				for(j = 1; j < m; j++)
					printf("%d ", a[i][j]);
				printf("%d\n", a[i][m]);
			}
			putchar('\n');
		}
	}
	return 0;
}