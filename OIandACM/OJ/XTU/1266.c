#include <stdio.h>
#include <string.h>

int main()
{
	int r, b, g, ans;
	char s[10009];
	int i, j;

	while(scanf("%s", s) == 1){
		r = g = b = 0;
		ans = 0;
		for(i = 0; i < strlen(s); i++)
			if(s[i] == 'R')
				r++;
			else if(s[i] == 'G')
				g++;
			else
				b++;
		for(i = 0; i < r; i++)
			if(s[i] != 'R'){
				if(s[i] == 'G'){
					for(j = r; j < strlen(s); j++)
						if(s[j] == 'R'){
							ans++;
							s[j] = 'G';
							break;
						}
				}else{
					for(j = strlen(s) - 1; j > i; j--){
						if(s[j] == 'R'){
							ans++;
							s[j] = 'B';
							break;
						}
					}
				}
			}
		for(i = r; i < r + g; i++)
			if(s[i] != 'G'){
				for(j = r + g; j < strlen(s); j++){
					if(s[j] == 'G'){
						ans++;
						s[j] = 'B';
						break;
					}
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}