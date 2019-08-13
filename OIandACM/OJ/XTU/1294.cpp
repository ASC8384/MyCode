#include <bits/stdc++.h>
using namespace std;

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

char s[10009];
char f[10009];

int main()
{
	int k = init();

	while(k--){
		scanf("%s", s);
		int n = init();
		memset(f, 0, sizeof(f));
		for(int i = 1; i < strlen(s); i++)
			if(s[i] != s[i - 1])
				f[i - 1] = 1;// 0 ~ ll-1
		for(int i = 0; i < n; i++){
			int x = init();
			int y = init();
			int ans = 0;
			for(int j = x - 1; j < y - 1; j++)
				ans += f[j];
			printf("%d\n", ans);
		}
	}
	return 0;
}