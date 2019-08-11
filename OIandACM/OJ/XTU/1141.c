#include <stdio.h>

int main()
{
	int n, x;
	char s[2333];
	scanf("%d", &n);

	while(n--){
		scanf("%d", &x);
		int top = 0;
		if(x == 0){
			printf("0\n");
		}else{
			while(x){
				if(x % 3 == 2){
					s[++top] = '-';
					x = x / 3 + 1;
				}else if(x % 3 == 1){
					s[++top] = '1';
					x /= 3;
				}else{
					s[++top] = '0';
					x /= 3;
				}
			}
			for(int i = top; i > 0; i--)
				putchar(s[i]);
			putchar('\n');
		}
	}
	return 0;
}