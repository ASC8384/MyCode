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

const int mo = 1000000007;
char s[2333];

int main()
{
	while(~scanf("%s", s)){
		int ll = strlen(s);
		unsigned long long t = 1;
		unsigned long long p = 1;
		for(int i = 0; i < ll; i++){
			p *= 26 % mo;
			t = (t * 26 + s[i] - 'a') % mo;
		}
		printf("%I64d\n", t);
	}
	return 0;
}