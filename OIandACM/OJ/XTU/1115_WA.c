#include <stdio.h>
#include <string.h>

int main()
{
	char s[233], t;
	int k, n, ll, i;
	scanf("%d", &n);

	while(n--){
		scanf("%s", s);
		scanf("%d%d", &k, &ll);
		t = 1;
		for(i = 0; i < (ll >> 1); i++){
			if(s[i + k - 1] != s[k + ll - 2 - i])
				t = 0;
			break;
		}
		if(t)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}