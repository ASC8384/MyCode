#include <algorithm>
#include <cstdio>
using namespace std;

unsigned long long min(unsigned long long x, unsigned long long y) {
	return x < y ? x : y;
}

unsigned long long a[5842];
unsigned long long b[10];

int main() {
	int n;

	a[1] = b[2] = b[3] = b[5] = b[7] = 1;
	for(int i = 2; i <= 5843; i++) {
		a[i] = min(min(a[b[2]] * 2, a[b[3]] * 3), min(a[b[5]] * 5, a[b[7]] * 7));
		if(a[i] == a[b[2]] * 2)
			b[2]++;
		if(a[i] == a[b[3]] * 3)
			b[3]++;
		if(a[i] == a[b[5]] * 5)
			b[5]++;
		if(a[i] == a[b[7]] * 7)
			b[7]++;
	}
	sort(a, a + 5843);
	while(scanf("%d", &n) && n) {
		if(n % 10 == 1 && n % 100 != 11)
			printf("The %dst humble number is %lld.\n", n, a[n]);
		else if(n % 10 == 2 && n % 100 != 12)
			printf("The %dnd humble number is %lld.\n", n, a[n]);
		else if(n % 10 == 3 && n % 100 != 13)
			printf("The %drd humble number is %lld.\n", n, a[n]);
		else
			printf("The %dth humble number is %lld.\n", n, a[n]);
	}
	return 0;
}