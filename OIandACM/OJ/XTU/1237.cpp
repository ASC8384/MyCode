#include <cstdio>
#include <cctype>
#include <cmath>

bool is_prime(int n){
	if(n == 1)
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

int a[5000009];
bool f[5000009];

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
	int k = init();
	f[1] = f[0] = 1;
	for(register int i = 2; i * i < 5000009; i++)
		if (!f[i])
			for(register int j = i * i; j < 5000009; j += i)
				f[j] = true;
	for(int i = 3; i < 5000009; i++)
		a[i] = a[i-1] + (!f[i] && !f[i-2]);
	// for(int i = 1; i <= 5000000; i += 2){
	// 	if(is_prime(i) && is_prime(i + 2)){
	// 		a[i + 2] = a[i - 1] + 1;
	// 		a[i] = a[i + 1] = a[i - 1];
	// 	}else{
	// 		a[i] = a[i + 1] = a[i - 1];
	// 	}
	// }// slow

	while(k--){
		int x = init();
		int y = init();
		if(y - x >= 2){
			printf("%d\n", a[y] - a[x+1]);// 奇偶
		}else{
			printf("0\n");
		}
	}
	return 0;
}