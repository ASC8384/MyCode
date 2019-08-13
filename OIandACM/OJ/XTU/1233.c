#include <stdio.h>
#include <ctype.h>

inline int init(void){
	int x; 
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

char s[233][233];

int main()
{
	int k = init();

	while(k--){
		int n = init();
		for(int i = n - 1; i >= 0; i--){
			for(int j = i + 1; j <= 2 * n - i - 1; j++)
				s[2*n - i - 1][j] = s[i + 1][j] = s[j][2*n - i - 1] = s[j][i + 1] = 'A' + n - i - 1;
		}
		for(int i = 1; i <= 2*n - 1; i++){
			for(int j = 1; j <= 2*n - 1; j++)
				printf("%c", s[i][j]);
			printf("\n");
		}
	}
	return 0;
}