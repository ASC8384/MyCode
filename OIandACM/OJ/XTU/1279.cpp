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

const int size = 1000009;
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

int a[size];

int main()
{
	make_prime(size);
	int t = init();
	for(int i = 1; i <= pri_top; i++){
		if(pri[i] * pri[i] >= size)
			break;
		for(int j = i + 1; j <= pri_top; j++){
			if(pri[i] * pri[j] >= size)
				break;
			else
				a[pri[i] * pri[j]] = 1;
		}
	}
	for(int i = 1; i <= size; i++)
		a[i] += a[i-1];

	while(t--){
		int x = init() - 1;
		printf("%d\n", a[init()] - a[x]);
	}
	return 0;
}