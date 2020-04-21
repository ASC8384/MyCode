/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 *
 * https://leetcode-cn.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (45.27%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    13K
 * Total Submissions: 28.6K
 * Testcase Example:  '[[1,2]]'
 *
 * 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
 *
 * 注意:
 *
 *
 * 可以认为区间的终点总是大于它的起点。
 * 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
 *
 *
 * 示例 1:
 *
 *
 * 输入: [ [1,2], [2,3], [3,4], [1,3] ]
 *
 * 输出: 1
 *
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 *
 *
 * 示例 2:
 *
 *
 * 输入: [ [1,2], [1,2], [1,2] ]
 *
 * 输出: 2
 *
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 *
 *
 * 示例 3:
 *
 *
 * 输入: [ [1,2], [2,3] ]
 *
 * 输出: 0
 *
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 *
 *
 */

// @lc code=start
class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b) {
		return a[1] < b[1];
	}

	int eraseOverlapIntervals(vector<vector<int>> &intervals) {
		int ll = intervals.size();
		if(ll == 0)
			return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int ed	= intervals[0][1];
		int ans = 1;
		for(int i = 1; i < ll; i++) {
			if(intervals[i][0] >= ed) {
				ans++;
				ed = intervals[i][1];
			}
		}
		return (ll - ans);
	}
};
// @lc code=end
