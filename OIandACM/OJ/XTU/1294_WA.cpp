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
int f[10009];

int main()
{
	int k = init();

	while(k--){
		scanf("%s", s);
		int n = init();
		f[0] = 0;
		if(strlen(s) > 1 && s[0] != s[1])
			f[1] = 1;
		else
			f[1] = 0;
		int i;
		for(i = 2; i < strlen(s); i++)
			if(s[i] != s[i - 1])
				f[i - 1] = f[i - 2] + 1;
			else
				f[i - 1] = f[i - 2];
		if(s[i - 1] != s[i - 2])
			f[i - 1] = f[i - 2] + 1;
		else
			f[i - 1] = f[i - 2];
		for(int i = 0; i < n; i++){
			int x = init();
			printf("%d\n", f[init() - 1] - f[x - 1]);
		}
	}
	return 0;
}