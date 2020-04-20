/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
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
				return vector<int>{le, ri};
			}
		}
	}
};
// @lc code=end
