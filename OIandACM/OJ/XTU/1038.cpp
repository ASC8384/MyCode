#include <cstdio>
#include <cctype>

inline int init(void){
	int x;
	char c;
	for(c = getchar(); !isdigit(c); c = getchar());
	for(x = 0; isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x;
}

int main()
{
	int k, n;
	int stk[23333], ans[23333];
	int top, t, pos, tmp;
	//scanf("%d", &k);
	k = init();

	while(k--){
		n = init();
		//scanf("%d", &n);
		top = t = 0;
		ans[0] = 0;
		while(n--){
			tmp = init();
			for(int i = 0; i < tmp-t; i++){
				stk[++top] = 0;
				ans[top] = ans[top-1];
			}
			t = tmp;
			stk[++top] = 1;
			ans[top] = ans[top-1] + 1;
		}
		for(int i = 1; i < top; i++){
			if(stk[i]){
				pos = i;
				while(--pos){
					if(stk[pos] == 0){
						stk[pos]++;
						printf("%d ", ans[i]-ans[pos]);
						break;
					}
				}
			}
		}
		pos = top;
		while(--pos){
			if(stk[pos] == 0){
				stk[pos]++;
				printf("%d", ans[top]-ans[pos]);
				break;
			}
		}
		putchar('\n');
	}
	return 0;
}