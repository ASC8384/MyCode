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

bool simple_is_prime(int n){
	if(n <= 1)// 0
		return false;
	if(n == 2 || n == 3)
		return true;
	if(n % 6 != 1 && n % 6 != 5)
		return false;
	int t = sqrt(n);
	for(register int i = 5; i <= t; i += 6)
		if(n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}

int main()
{
	int k = init();

	while(k--){
		int n = init();
		//string s = to_string(n);
		if(simple_is_prime(n)){
			int t;
			char f = 1;
			while(n && f){
				t = 0;
				int p = 1;
				do{
					if(n % 10 == 0){
						//printf("No\n");
						f = 0;
						break;
					}
					t = t + n % 10 * p;
					n /= 10;
					p *= 10;
				}while(n >= 10);
				if(!simple_is_prime(t) || t == 0){
					//printf("No\n");
					f = 0;
					break;
				}else if(n > 10)
					n = t;
				else
					n = 0;
			}
			if(f)
				printf("Yes\n");
			else
				printf("No\n");
			/*s.erase(0);
			n = stoi(s);
			while(s[0] != '0' && n && simple_is_prime(n)){
				s.erase(0);
				n = stoi(s);
			}
			if(n != 0)
				printf("No\n");
			else
				printf("Yes\n");*/
		}else{
			printf("No\n");
		}
	}
	return 0;
}