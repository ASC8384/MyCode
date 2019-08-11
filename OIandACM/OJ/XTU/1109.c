#include <stdio.h>
#include <string.h>

int main()
{
	char s[23][233];
	int k, n;
	int minl, i, j, z;
	scanf("%d", &k);
	
	for(z = 1; z <= k; z++){
		scanf("%d", &n);
		printf("Case %d: ", z);
		minl = 2333;
		for(i = 0; i < n; i++){
			scanf("%s", s[i]);
			if(strlen(s[i]) < minl)
				minl = strlen(s[i]);
		}
		for(i = 0; i < minl; i++){
			for(j = 0; j < n - 1; j++)
				if(s[j][i] != s[j + 1][i]){
					j = 2333;
                    break;
                }
            if(j != 2333)
			    printf("%c", s[0][i]);
            else
                break;
		}
		printf("\n");
	}
	return 0;
}