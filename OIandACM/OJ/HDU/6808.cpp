#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define MAX 100009
using namespace std;
int n, m;
struct Edge {
	int u, v;
};
struct Point {
	int id;
	int degree, adj_degree;
} point[MAX];
vector<Edge> E;
vector<int>	 G[MAX];
int			 degree[MAX], adj_degree[MAX]; //每个点的度数和邻接度数
bool		 del[MAX], vis[MAX];
int			 V_cnt, Vv_cnt, E_cnt;
void		 init_edge(int n) {
	E.clear();
	for(int i = 1; i <= n; i++)
		G[i].clear();
}
void add_edge(int u, int v) {
	E.push_back((Edge){u, v});
	E.push_back((Edge){v, u});
	int _size = E.size();
	G[u].push_back(_size - 2);
	G[v].push_back(_size - 1);
}
bool cmp(Point a, Point b) { return a.adj_degree > b.adj_degree; }
int	 pretreat() {
	 for(int i = 1; i <= n; i++) {
		 point[i].degree = 0;
		 if(del[i])
			 continue;
		 for(int j = 0, _size = G[i].size(); j < _size; j++) {
			 Edge &e = E[G[i][j]];
			 if(!del[e.v])
				 point[i].degree++;
		 }
		 if(point[i].degree == 0)
			 del[i] = 1;
	 }
	 for(int i = 1; i <= n; i++) {
		 if(del[i]) {
			 point[i].adj_degree = 0;
			 continue;
		 }
		 point[i].adj_degree = point[i].degree;
		 for(int j = 0, _size = G[i].size(); j < _size; j++)
			 point[i].adj_degree += point[E[G[i][j]].v].degree;
		 //  printf("adj_degree[%d] = %d\n", i, point[i].adj_degree);
	 }
	 sort(point + 1, point + n + 1, cmp);
}
void MinVC_MGA(bool ans[]) {
	memset(del, 0, sizeof(del));
	for(int i = 1; i <= n; i++)
		point[i].id = i;
	E_cnt = 0;
	while(E_cnt < m) {
		memset(vis, 0, sizeof(vis));
		pretreat();
		V_cnt  = 0;
		Vv_cnt = 0;
		for(int i = 1; i <= n; i++)
			if(!del[i])
				Vv_cnt++;
		for(int i = 1; i <= n; i++) {
			// printf("del[%d]=%d vis[%d]\n", point[i].id, del[point[i].id], point[i].id, vis[point[i].id]);
			if(del[point[i].id])
				continue;
			if(vis[point[i].id])
				continue;
			// printf("now ans add: %d\n", point[i].id);
			ans[point[i].id] = 1; //加入到最小顶点覆盖集中
			del[point[i].id] = 1, Vv_cnt--;
			for(int j = 0, _size = G[point[i].id].size(); j < _size; j++) {
				Edge &e = E[G[point[i].id][j]];
				if(del[e.v])
					continue;
				E_cnt++;
				if(!vis[e.v]) {
					vis[e.v] = 1;
					V_cnt++;
				}
			}
			if(V_cnt >= Vv_cnt)
				break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		map<int, int> M;
		cin >> n;
		init_edge(n * 2);
		int x = 0;
		m	  = n * 2;
		for(int i = 1; i <= n; i++) {
			int a, b;
			// scanf("%d%d", &a, &b);
			cin >> a >> b;
			int c = b - a, d = b + a;
			if(!M.count(c))
				M[c] = ++x;
			if(!M.count(d))
				M[d] = ++x;
			int l = M[c], r = M[d];
			add_edge(l, r);
			add_edge(r, l);
		}
		bool ans[n + 5];
		memset(ans, 0, sizeof(ans));
		MinVC_MGA(ans);
		int ou = 0;
		for(int i = 1; i <= n; i++)
			ou += ans[i];
		cout << ou << '\n';
	}
}
