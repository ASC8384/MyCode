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

const int size = 1000000;
bool isp[size];
int pri[size];
int pri_top;

void make_prime(int maxn){
	memset(isp, true, sizeof(isp));
	isp[0] = isp[1] = false;
	for(int i = 2; i <= maxn; i++){
		if(isp[i])
			pri[++pri_top] = i;
		for(int j = 1; j <= pri_top && i * pri[j] <= maxn; j++){
			isp[i * pri[j]] = false;
			if(!(i % pri[j]))
				break;
		}
	}
}

int a[size + 1];

int main()
{
	make_prime(size);
	for(int i = 3; i <= pri_top; i++){
		unsigned long long tmp = (pri[i - 1] + pri[i]) >> 1;
		if(tmp > size)
			break;
		if(!isp[tmp]){
			a[tmp] = 1;
		}
	}
	for(int i = 1; i < size; i++)
		a[i] += a[i - 1];
	int t = init();

	while(t--){
		int x = init() - 1;
		printf("%d\n", a[init()] - a[x]);
	}
	return 0;
}