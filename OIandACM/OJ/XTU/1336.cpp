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

int a[] = {11, 1001, 100001, 101101, 110011};
// int a[] = {11, 1001, 1111, 100001, 101101, 110011, 111111};

int main()
{
	int t = init();

	while(t--){
		int n = init();
		int ans;
		;
	}
	return 0;
}