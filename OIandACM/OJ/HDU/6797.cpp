#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((ll)(x).size())
typedef vector<ll>	 VI;
typedef pair<ll, ll> PII;

const ll mod = 1e9 + 7;
const ll N	 = 1e5 + 6;

int			  t, p[50], n, k;
int			  ans;
map<int, int> mp;

struct Edge {
	int u, v, w, next;
} e[5500];
int head[550], cnt, vis[550], dis[550];
struct node {
	int			w, now;
	inline bool operator<(const node &x) const
	//重载运算符把最小的元素放在堆顶（大根堆）
	{
		return w > x.w; //这里注意符号要为'>'
	}
};
priority_queue<node> q;
//优先队列，其实这里一般使用一个pair，但为了方便理解所以用的结构体
inline void add(int u, int v, int w) {
	e[++cnt].u = u;
	//这句话对于此题不需要，但在缩点之类的问题还是有用的
	e[cnt].v	= v;
	e[cnt].w	= w;
	e[cnt].next = head[u];
	//存储该点的下一条边
	head[u] = cnt;
	//更新目前该点的最后一条边（就是这一条边）
}
//链式前向星加边
void dijkstra() {
	while(!q.empty())
		q.pop();
	for(int i = 1; i <= n; i++) {
		dis[i] = 99999999;
	}
	dis[1] = 0;
	memset(vis, 0, sizeof(vis));
	//赋初值
	q.push((node){0, 1});
	while(!q.empty())
	//堆为空即为所有点都更新
	{
		node x = q.top();
		q.pop();
		int u = x.now;
		//记录堆顶（堆内最小的边）并将其弹出
		if(vis[u])
			continue;
		//没有遍历过才需要遍历
		vis[u] = 1;
		for(int i = head[u]; i; i = e[i].next)
		//搜索堆顶所有连边
		{
			int v = e[i].v;
			if(mp[v] == 1)
				continue;
			if(dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				//松弛操作
				q.push((node){dis[v], v});
				//把新遍历到的点加入堆中
			}
		}
	}
}

void solve() {
	memset(head, 0, sizeof(head));
	scanf("%d%d", &n, &k);
	ans = cnt = 0;
	memset(p, 0, sizeof(p));
	for(int u, v, w, i = 1; i <= (n * (n - 1)) / 2; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for(int i = 1; i < n - 1; i++)
		p[i] = i + 1;
	int size;
	if(n <= 30)
		size = n * max(n, 15);
	else
		size = n * n;
	for(int i = 1; i <= size; i++) {
		swap(p[rand() % n + 1], p[rand() % n + 1]);
		// random_shuffle(p + 1, p + n - 1);
		// if(i & 1)
		// 	random_shuffle(p + 1, p + (n >> 1) + 1);
		// else
		// 	random_shuffle(p + (n >> 1), p + n - 1);
		mp.clear();
		for(int j = 1; j <= k; j++)
			mp[p[j]] = 1;
		dijkstra();
		// if(ans > dis[n])
		// ans = dis[n];
		ans = max(ans, dis[n]);
	}
	// cout << ans << '\n';
	printf("%d\n", ans);
}

int main() {
	srand((unsigned)time(NULL));
	scanf("%d", &t);
	while(t--) {
		solve();
	}
}
