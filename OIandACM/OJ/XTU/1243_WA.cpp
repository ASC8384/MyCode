#include <bits/stdc++.h>
using namespace std;

char flag[11];
int top[] = {0, 5, 7, 5, 7, 8, 7, 5, 7, 5};
int a[][10] = {{0},{2, 4, 5, 6, 8},
				{1, 3, 4, 5, 6, 7, 9},
				{2, 4, 5, 6, 8},
				{1, 2, 3, 5, 7, 8, 9},
				{1, 2, 3, 4, 6, 7, 8, 9},
				{1, 2, 3, 5, 7, 8, 9},
				{2, 4, 5, 6, 8},
				{1, 3, 4, 5, 6, 7, 9},
				{2, 4, 5, 6, 8}
			};

int main()
{
	int t, x;
	char s[12];
	scanf("%d", &t);

	while(t--){
		scanf("%s", s);
		memset(flag, 0, sizeof(flag));
		x = s[0] - '0';
		for(int i = 0; i < top[x]; i++)
			flag[a[x][i]] = 1;
		for(int i = 1; i < strlen(s); i++){
			x = s[i] - '0';
			if(flag[x])
				for(int i = 0; i < top[x]; i++)
					flag[a[x][i]] = 1;
			else{
				x = -1;
				break;
			}
		}
		if(x == -1)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}