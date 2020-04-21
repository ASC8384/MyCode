/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (61.09%)
 * Likes:    316
 * Dislikes: 0
 * Total Accepted:    49.4K
 * Total Submissions: 80.8K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 *
 * 示例 1:
 *
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 *
 * 示例 2:
 *
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 * 说明：
 *
 *
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 *
 *
 */

// @lc code=start
class Solution {
public:
	static bool cmp(pair<int, int> x, pair<int, int> y) {
		return x.second > y.second;
	}

	vector<int> topKFrequent(vector<int> &nums, int k) {
		map<int, int> mapp;
		for(auto &i : nums)
			mapp[i]++;
		vector<pair<int, int>> a(mapp.begin(), mapp.end());
		sort(a.begin(), a.end(), cmp);
		int			n = nums.size();
		vector<int> ans(k);
		// for(int i = 0; i < a.size(); i++)
		//     cout << a[i].first <<" "<< a[i].second << endl;
		for(int i = 0; i < k; i++)
			ans[i] = a[i].first;
		return ans;
	}
};
/*
[1,1,1,2,2,3]
2
[4,1,-1,2,-1,2,3]
2
*/
// @lc code=end
