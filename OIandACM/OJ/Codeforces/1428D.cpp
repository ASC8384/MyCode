#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int	 A[110000];
bool B[110000];
struct L {
	int a, b;
};
int main() {
	int t;
	t = 1;
	while(t--) {
		int n;
		scanf("%d", &n);
		int		 a1 = 0, a2 = 0;
		int		 ans = 0;
		queue<L> q1, q2, q3;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &A[i]);
			B[i] = 0;
			if(A[i] == 0)
				continue;
			if(A[i] == 1) {
				ans++;
				q1.push({i, 0});
				if(a2)
					a2--;
				else if(a1)
					a1--;
			}
			if(A[i] == 2) {
				ans++;
				if(a1)
					a1--;
				a2++;
				q2.push({i, 0});
			}
			if(A[i] == 3) {
				ans += 2;
				if(a1)
					a1--;
				a1++;
				q3.push({i, 0});
			}
		}
		if(a1 || a2) {
			printf("-1\n");
			continue;
		}
		int k = 0;
		int o = 0;
		printf("%d\n", ans);
		L s;
		if(!q3.empty()) {
			s = q3.front();
			q3.pop();
			s.b = ++k;
			printf("%d %d\n", s.b, s.a);
			while(!q3.empty()) {
				L a = q3.front();
				q3.pop();
				a.b = s.b + 1;
				printf("%d %d\n%d %d\n", a.b - 1, a.a, a.b, a.a);
				s = a;
				k = max(k, s.b);
			}
			for(int i = s.a + 1; i <= n; i++)
				if(A[i] == 1 || A[i] == 2) {
					printf("%d %d\n", s.b, i);
					printf("%d %d\n", ++s.b, i);
					o = i;
					k = max(k, s.b);
					break;
				}
		}
		while(!q2.empty() || !q1.empty()) {
			if(q2.empty()) {
				while(!q1.empty()) {
					L a = q1.front();
					q1.pop();
					printf("%d %d\n", ++k, a.a);
				}
				break;
			}
			L a = q2.front();
			L b = q1.front();
			if(b.a == o) {
				q1.pop();
				continue;
			}
			while(b.a < a.a) {
				q1.pop();
				b = q1.front();
			}
			if(a.a == o)
				printf("%d %d\n", s.b, b.a);
			else {
				k++;
				printf("%d %d\n%d %d\n", k, b.a, k, a.a);
			}

			q1.pop();
			q2.pop();
		}
	}
}