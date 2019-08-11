#include <bits/stdc++.h>

int main()
{
	int k;
	int n, m;
	char c;
	int x, y;
	int a[12][12], t[12];
	// vector <int> a[12];
	scanf("%d", &k);

	while(k--){
		scanf("%d%d\n", &n, &m);
		int top = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				// a[i].push_back(i * j);
				a[i][j] = ++top;
		for(int i = 1; i <= m; i++){
			scanf("%c%d%d\n", &c, &x, &y);
			if(c == 'L'){
				for(int j = 1; j <= y; j++)
					t[j] = a[x][j];
				for(int j = y + 1; j <= n; j++)
					a[x][j - y] = a[x][j];
				for(int j = n + 1 - y; j <= n; j++)
					a[x][j] = t[j - n + y];
			}else if(c == 'R'){
				for(int j = 1; j <= y; j++)
					t[j] = a[x][n - y + j];
				for(int j = n; j > y; j--)
					a[x][j] = a[x][j - y];
				for(int j = 1; j <= y; j++)
					a[x][j] = t[j];
			}else if(c == 'U'){
				for(int j = 1; j <= y; j++)
					t[j] = a[j][x];
				for(int j = y + 1; j <= n; j++)
					a[j - y][x] = a[j][x];
				for(int j = n + 1 - y; j <= n; j++)
					a[j][x] = t[j - n + y];
			}else{
				for(int j = 1; j <= y; j++)
					t[j] = a[n - y + j][x];
				for(int j = n; j > y; j--)
					a[j][x] = a[j - y][x];
				for(int j = 1; j <= y; j++)
					a[j][x] = t[j];
			}
		}
		for(int i = 1; i < n; i++)
			for(int j = 1; j <= n; j++)
				printf("%d ", a[i][j]);
		for(int i = 1; i < n; i++)
			printf("%d ", a[n][i]);
		printf("%d", a[n][n]);
		putchar('\n');
		//cout << endl;
	}
	return 0;
}