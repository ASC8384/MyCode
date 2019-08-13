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
		for(i = strlen(s) >> 1; i; i--){// len
			for(j = 0; j <= strlen(s) - 2*i; j++){
				for(k = j; k < i + j; k++){
					if(s[k] != s[k + i])
						break;
				}
				if(k == i + j){
					printf("%d\n", i << 1);
					break;
				}
			}
			if(j <= strlen(s) - 2*i)// is
				break;
		}
	}
	return 0;
}