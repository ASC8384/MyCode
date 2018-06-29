/**********************************************************************
*                              Floyd.c                               *
**********************************************************************/
/* 
** Copyright	Human
** Author		ASC_8384
** Mail			ASC_8384@foxmail.com
** Website		http://ASC8384.top
** FileName		Floyd.c
** Description	Floyd-Warshall算法 求最短路径
** HomepageURL	https://github.com/ASC8384/MyCodeSnippets
** License		CC0
*/
for(k = 1; k <= n; k++)
	for(j = 1; j <= n; j++)
		if(k != j)
			for(i = 1; i <= n; i++)
				if(k != i)
					if(i != j)
						if(*(*(dis + i) + j) > *(*(dis + i) + k) + *(*(dis + k) + j))
							*(*(dis + i) + j) = *(*(dis + i) + k) + *(*(dis + k) + j);

//存图于dis[][]
//计算的是图中任意一点到其余任意一点的距离

for (int k = 1; k <= n; k++)
	for (int i = 1; i <= n; i++)
		if (k != i)
			for (int j = 1; j <= n; j++)
				if (j != k)
					if (i != j)
						if (dis[i][j] > dis[i][k] + dis[k][j])
							dis[i][j] = dis[i][k] + dis[k][j];

/* 
let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)

for each vertex v
	dist[v][v] ← 0
for each edge (u,v)
	dist[u][v] ← w(u,v)
*/
