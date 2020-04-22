/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 *
 * https://leetcode-cn.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (60.21%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 15.1K
 * Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
 *
 * 给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。
 *
 * 示例 1:
 *
 *
 * 输入: [1,1,2,3,3,4,4,8,8]
 * 输出: 2
 *
 *
 * 示例 2:
 *
 *
 * 输入: [3,3,7,7,10,11,11]
 * 输出: 10
 *
 *
 * 注意: 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。
 *
 */

// @lc code=start
class Solution {
public:
	int singleNonDuplicate(vector<int> &nums) {
		int ll = 0;
		int ri = nums.size() - 1;
		while(ll < ri) {
			unsigned long long mid = (ll + ri) / 2;
			if(mid & 1)
				mid--;
			if(nums[mid] == nums[mid + 1]) {
				ll = mid + 2;
			} else { // if(nums[mid] == nums[mid - 1]) {
				ri = mid;
			}
			// } else {
			// 	return nums[mid];
			// }
		}
		return nums[ll];
	}
};
// @lc code=end
