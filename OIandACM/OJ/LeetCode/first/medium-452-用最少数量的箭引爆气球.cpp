/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 *
 * https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (49.68%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 25.4K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 *
 * 在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在10^4个气球。
 *
 * 一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart
 * ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。
 * 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
 *
 * Example:
 *
 *
 * 输入:
 * [[10,16], [2,8], [1,6], [7,12]]
 *
 * 输出:
 * 2
 *
 * 解释:
 * 对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。
 *
 *
 */

// @lc code=start
class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b) {
		if(a[1] == b[1])
			return a[0] < b[0];
		return a[1] < b[1];
	}

	int findMinArrowShots(vector<vector<int>> &points) {
		int ll = points.size();
		if(ll < 2)
			return ll;
		sort(points.begin(), points.end(), cmp);
		int ans = 1;
		int ed	= points[0][1];
		for(int i = 1; i < ll; i++) {
			if(points[i][0] > ed) {
				ed = points[i][1];
				++ans;
			}
		}
		return ans;
	} // nlogn+n
};
// @lc code=end
