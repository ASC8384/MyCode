#include <bits/stdc++.h>
using namespace std;

int a[500009];
int f[500009];

void merge(int ll, int rr) {
	if(ll == rr) {
		f[ll] = a[ll];
		return;
	}
	int minn = ll;
	int minl = ll;
	int minr = rr;
	for(int i = ll; i <= rr; i++)
		if(a[i] < a[minn])
			minn = i;
	f[minn] = a[minn];
	for(int i = ll; i <= minn - 1; i++)
		if(a[i] < a[minl])
			minl = i;
	for(int i = minn + 1; i <= rr; i++)
		if(a[i] < a[minr])
			minr = i;
	if((minn - ll) * a[minl] < (rr - minn) * a[minr]) { // left
		for(int i = ll; i <= minn; i++)
			f[i] = a[minn];
		merge(minn + 1, rr);
	} else {
		for(int i = minn; i <= rr; i++)
			f[i] = a[minn];
		merge(ll, minn - 1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	merge(1, n);

	for(int i = 1; i <= n; i++)
		printf("%d ", f[i]);
	return 0;
}
// 13
// 4 2 4 3 4 2 4 1 10 8 10 9 10