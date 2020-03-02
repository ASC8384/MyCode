#include <bits/stdc++.h>
using namespace std;

int a[500009];
int f[500009];

unsigned long long merge(int ll, int rr, int minn) {
	if(ll >= rr) {
		f[ll] = a[ll];
		return a[ll];
	}

	int minl  = ll;
	int minr  = rr;
	int minnl = minn;
	int minnr = minn;
	while(a[minn] == a[minnl - 1])
		minnl--;
	while(a[minn] == a[minnr + 1])
		minnr++;
	for(int i = ll; i <= minnl - 1; i++)
		if(a[i] < a[minl])
			minl = i;
	for(int i = minnr + 1; i <= rr; i++)
		if(a[i] < a[minr])
			minr = i;

	unsigned long long suml = merge(minnr + 1, rr, minr);
	unsigned long long sumr = merge(ll, minnl - 1, minl);
	if(suml >= sumr) { // left smaller
		for(int i = ll; i <= minnr; i++)
			f[i] = a[minn];
		return sumr + (minnl - ll) * a[minl];
	} else {
		for(int i = minnl; i <= rr; i++)
			f[i] = a[minn];
		return suml + (rr - minnr) * a[minr];
	}
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int minn = 1;
		for(int i = 1; i <= n; i++)
			if(a[i] < a[minn])
				minn = i;
		merge(1, n, minn);
		for(int i = 1; i < n; i++)
			printf("%d ", f[i]);
		printf("%d\n", f[n]);
	}
	return 0;
}
/*
6
11 2 1 2 3 4
11 2 1 1 1 1

6
4 3 2 2 4 6
2 2 2 2 4 6

13
4 2 4 3 4 2 4 1 10 8 10 9 10
1 1 1 1 1 1 1 1 8 8 10 9 9
*/