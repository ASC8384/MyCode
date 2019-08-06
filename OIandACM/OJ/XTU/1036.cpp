#include <cstdio>
#include <cstring>
#include <cctype>

int main()
{
	int k;
	char s[2333];
	int stk[2333];
	int top, x;
	scanf("%d\n", &k);

	for(int i = 0; i < k; i++){
		//scanf("%s\n", s);
		gets(s);
		x = top = 0;
		for(unsigned int j = 0; j < strlen(s); j++){
			if(isdigit(s[j])){
				x = x*10 + s[j] - '0';
			}else
			if(s[j] == ' '){
				stk[++top] = x;
				x = 0;
			}else{
				switch(s[j]){
					case '+': 	stk[top-1] += stk[top];top--;
								break;
					case '-': 	stk[top-1] -= stk[top];top--;
								break;
					case '*': 	stk[top-1] *= stk[top];top--;
								break;
					case '/': 	stk[top-1] /= stk[top];top--;
								break;
					case '%': 	stk[top-1] %= stk[top];top--;
								break;
				}
				j++;
			}
		}
		printf("%d\n", stk[top]);
	}
	return 0;
}