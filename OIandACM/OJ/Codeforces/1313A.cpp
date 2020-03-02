#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) { return x > y; }
int  main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		 int a[5];
		 scanf("%d%d%d", &a[1], &a[2], &a[3]);

		 sort(a + 1, a + 4, cmp);

		 int ans = 0;

		 for(int i = 1; i <= 3; i++)
			 if(a[i])
				 ans++, a[i]--;
		 for(int i = 2; i <= 3; i++)
			 if(a[1] && a[i]) {
				 a[1]--;
				 a[i]--;
				 ans++;
			 }
		 if(a[2] && a[3]) {
			 a[2]--;
			 a[3]--;
			 ans++;
		 }
		 if(a[1] && a[2] && a[3])
			 ans++;
		 printf("%d\n", ans);
	}
	return 0;
}
