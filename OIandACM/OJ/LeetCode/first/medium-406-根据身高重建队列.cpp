/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 *
 * https://leetcode-cn.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (64.22%)
 * Likes:    290
 * Dislikes: 0
 * Total Accepted:    24.5K
 * Total Submissions: 38.1K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
 * 编写一个算法来重建这个队列。
 *
 * 注意：
 * 总人数少于1100人。
 *
 * 示例
 *
 *
 * 输入:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *
 * 输出:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 *
 *
 */

// @lc code=start
class Solution {
public:
	static bool cmp(vector<int> a, vector<int> b) {
		if(a[0] == b[0])
			return a[1] < b[1];
		else
			return a[0] > b[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
		int ll = people.size();
		if(ll < 2)
			return people;
		sort(people.begin(), people.end(), cmp);
		list<vector<int>> a;
		for(auto &i : people) {
			auto iter = a.begin();
			advance(iter, i[1]);
			a.insert(iter, i);
		}
		return (vector<vector<int>>(a.begin(), a.end()));
	}
};
// @lc code=end
