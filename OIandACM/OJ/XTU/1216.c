#include <stdio.h>
#include <string.h>

int a[233];

int main()
{
	char s[233];
	int i;
	a['I'] = 1;
	a['V'] = 5;
	a['X'] = 10;
	a['L'] = 50;
	a['C'] = 100;
	a['D'] = 500;
	a['M'] = 1000;

	while(~scanf("%s", s)){
		int ans = 0;
		for(i = 0; i < strlen(s) - 1; i++)
			if(s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')){
				ans -= a[s[i]];
			}else if(s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')){
				ans -= a[s[i]];
			}else if(s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')){
				ans -= a[s[i]];
			}else{
				ans += a[s[i]];
			}
		ans += a[s[i]];
		printf("%d\n", ans);
	}
	return 0;
}