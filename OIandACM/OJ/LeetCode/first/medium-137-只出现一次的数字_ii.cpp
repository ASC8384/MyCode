/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 *
 * https://leetcode-cn.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (66.55%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    31.3K
 * Total Submissions: 46.7K
 * Testcase Example:  '[2,2,3,2]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
 *
 * 说明：
 *
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 *
 * 示例 1:
 *
 * 输入: [2,2,3,2]
 * 输出: 3
 *
 *
 * 示例 2:
 *
 * 输入: [0,1,0,1,0,1,99]
 * 输出: 99
 *
 */

// @lc code=start
class Solution {
public:
	int singleNumber(vector<int> &nums) {
		int a = 0, b = 0;
		for(auto num : nums) {
			a = (a ^ num) & ~b;
			b = (b ^ num) & ~a;
		}
		return a;
	}
};
// @lc code=end
