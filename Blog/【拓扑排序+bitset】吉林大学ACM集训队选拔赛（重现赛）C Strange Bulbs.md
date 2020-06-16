# 【拓扑排序+bitset】吉林大学ACM集训队选拔赛（重现赛）C Strange Bulbs

## 题目大意

一张图，开始灯1只有亮，每次开关当前灯，后面所有和它联通的灯的状态也变了；要求全暗的操作次数。

## 思路

显而易见，我们对节点的操纵是按层来的，当前的会影响后面，后面的影响不了父节点，所以用拓扑排序。当前节点的变化也关联着它所有的子节点，而当前节点是否需要开关则是看它的所有开关过的父节点的数量的奇偶性，奇开偶不开。所以我们需要一个东西，来保存它的所有开关过的父节点的数量，且数量不能重复记录，这里就要用到 bitset 了。

这里我因为太弱，以为如果当前节点有偶数个开关过的父节点，那么当前节点的子节点就不用参与拓扑排序了，因为它自己没对子节点们产生影响。然而，如果子节点有多个父节点，比如某节点它，它儿子和它父亲连着的话，就会直接略过了，但实际上它应该是1+1+1，还得继续来次操作。所以偶数个的也要参与拓扑排序。

比如该例子（@Quuns巨巨提供）：

``` 
6 8
1 2
1 3
1 4
2 5
2 6
3 6
4 6
3 2
```

1. 算个 topo 序
2. 根据当前节点的所有开关过的父节点的数量的奇偶性
  + 奇:ans++
  + 偶:不动

|bit|含义|
|-|-|
|bit.count()|返回1的个数|
|bit.set(p, x)|将第p + 1位变成x|
|bit.any()|返回是否有1|
|bit.none()|返回是否没有1|
|bit.set()|全都变成1|
|bit.flip()|全都取反|

## 代码

``` cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long          ll;
typedef unsigned long long ull;
const int                  size = 4e4 + 9;

int          n, m;
int          in[size];
bitset<size> v[size];
int          ans = 0;

vector<int> g[size];
queue<int>    que;

void bfs(int pos) {
    for(int i = 1; i <= n; i++)
        if(in[i] == 0)
            que.push(i);
    v[1][1] = 1;
    // que.push(pos);
    while(!que.empty()) {
        pos = que.front();
        que.pop();
        if((v[pos].count() & 1) || pos == 1) {
            ans++;
            v[pos].set(pos, 1);
        }// 就是这个花括号的位置
            for(auto i : g[pos]) {
                // v[i] = !v[i];
                // v[i] += v[pos];
                // if(v[i] == 0)
                //  v[i] = v[pos];
                // v[i]++;
                in[i]--;
                v[i] |= v[pos];
                if(in[i] == 0)
                    que.push(i);
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    // qread(t);
    t = 1;
    while(t--) {
        qread(n, m);
        // if(n == m - )
        for(int i = 1; i <= m; i++) {
            int u, v;
            qread(u, v);
            g[u].push_back(v);
            in[v]++;
        }
        // v[1] = 0;
        bfs(1);
        cout << ans << endl;
    }

    return 0;
}
```
