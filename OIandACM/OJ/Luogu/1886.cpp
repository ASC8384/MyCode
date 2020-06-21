/***
 * @Author       : ASC_8384
 * @License      : CC0
 * @Website      : http://www.ASC8384.top
 * @FilePath     : \OIandACM\OJ\Luogu\1886.cpp
 * @Date         : 2020-05-04 21:42:35
 * @LastEditTime : 2020-05-04 21:42:35
 * @Description  : P1886
 */

#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1000009];

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	deque<pair<int, int> > q;
	for(int i = 1; i <= n; ++i) {
		while(!q.empty() && a[i] <= q.back().first)
			q.pop_back(); // 求最小的
		q.push_back({a[i], i});
		while(q.front().second <= i - k)
			q.pop_front();
		if(i >= k)
			printf("%d ", q.front().first);
	}
	putchar('\n');
	q.clear();
	for(int i = 1; i <= n; ++i) {
		while(!q.empty() && a[i] >= q.back().first)
			q.pop_back(); // 求最big的
		q.push_back({a[i], i});
		while(q.front().second <= i - k)
			q.pop_front();
		if(i >= k)
			printf("%d ", q.front().first);
	}
	return 0;
}