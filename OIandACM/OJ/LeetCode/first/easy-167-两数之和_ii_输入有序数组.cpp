/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int le = 0;
		int ri = numbers.size() - 1;
		while(le < ri) {
			int sum = numbers[le] + numbers[ri];
			if(sum < target) {
				le++;
			} else if(sum > target) {
				ri--;
			} else {
				return vector<int>{le + 1, ri + 1};
			}
		}
		return vector<int>{le + 1, ri + 1};
	}
};
// @lc code=end
