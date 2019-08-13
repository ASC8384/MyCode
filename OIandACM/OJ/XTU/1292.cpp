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

char s[2333];

int main()
{
	int n = init();
	int i, j, k;

	while(n--){
		scanf("%s", s);
		int ll = strlen(s);
		for(i = ll >> 1; i >= 0; i--){// len
			for(j = 0; j <= ll - (i<<1); j++){
				for(k = j; k < i + j; k++){
					if(s[k] != s[k + i])
						break;
				}
				if(k == i + j){
					printf("%d\n", i << 1);
					break;
				}
			}
			if(j <= ll - (i<<1))// is
				break;
		}
	}
	return 0;
}