#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

long long n;

void shit(long long a[], long long k) //a=a*k,k是单精度
{
	int i;
	for(i = 1; i <= a[0]; i++)
		a[i] *= k; //每位先乘起来
	for(i = 1; i <= a[0]; i++) {
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	} //处理进位
	while(a[a[0] + 1] > 0) {
		a[0]++;
		a[a[0] + 1] = a[a[0]] / 10;
		a[a[0]] %= 10;
	} //处理最高位相乘的进位
	a[0] = min(n, a[0]);
}

void ohno(long long a[], long long k) {
	int p = 0;
	for(int i = a[0]; i >= 1; i--) {
		p	 = p * 10 + a[i];
		a[i] = p / k;
		p %= k;
	}
	while(!a[a[0]])
		a[0]--;
}

long long P[110000], B[110000];
long long C[110000];
long long a[110000];
long long gcd(long long a, long long b) {
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

long long get(long long a[]) {
	long long ret = a[1];
	for(int i = 2; i <= 5; i++) {
		ret = ret * 10 + a[i];
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &P[i]);
	for(int i = 1; i <= n; i++)
		if(!B[i]) {
			C[0] = 1;
			C[1] = i;
			while(P[C[C[0]]] != C[1])
				C[++C[0]] = P[C[C[0] - 1]];
			int k = C[0];
			while(C[0])
				B[C[C[0]--]] = k;
		}
	a[0] = 1;
	a[1] = 1;
	shit(a, B[1]);
	for(int i = 2; i <= n; i++) {
		long long k = gcd(get(a), B[i]);
		shit(a, B[i]);
		ohno(a, k);
		// ans			= ans * B[i] / k;
	}

	for(int i = a[0]; i; i--) {
		// cout << a[i];
		printf("%d", a[i]);
	}
	return 0;
}

/*
** Author:	ASC_8384
** Website:	www.ASC8384.top
** License:	CC0
** Time:	2020-07-25 16:59:45
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int size = 2e5 + 9;
const ll  mod  = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        ;
    }

    return 0;
}