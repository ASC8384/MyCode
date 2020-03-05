#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

typedef struct now {
	int  fish;
	int  index;
	bool operator<(const now ob) const {
		return fish == ob.fish ? index > ob.index : fish < ob.fish;
	}
} now;

inline int max(const int a, const int b) { return a > b ? a : b; }

int n, h;
int f[88], t[88], d[88];
int ans[88];
int maxx;
int stay[88];

int main() {
	while(~scanf("%d", &n) && n) {
		scanf("%d", &h);
		for(int i = 1; i <= n; i++)
			scanf("%d", f + i);
		for(int i = 1; i <= n; i++)
			scanf("%d", d + i);
		t[1] = 0;
		for(int i = 2; i <= n; i++) {
			scanf("%d", t + i);
			t[i] += t[i - 1];
		}
		maxx = -1;

		for(int i = 1; i <= n; i++) {
			priority_queue<now> que;
			memset(stay, 0, sizeof(stay));
			int time = h * 12 - t[i];
			int sum  = 0;
			for(int j = 1; j <= i; j++)
				que.push(now{f[j], j});

			for(int j = 1; j <= time; j++) {
				now a = que.top();
				que.pop();
				sum += a.fish;
				stay[a.index]++;
				a.fish = max(0, a.fish - d[a.index]);
				que.push(a);
			}

			if(sum > maxx) {
				maxx = sum;
				for(int i = 1; i <= n; i++)
					ans[i] = stay[i];
			}
		}

		printf("%d", ans[1] * 5);
		for(int i = 2; i <= n; i++)
			printf(", %d", ans[i] * 5);
		printf("\nNumber of fish expected: %d\n\n", maxx);
	}
	return 0;
}