/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
	bool judgeSquareSum(int c) {
		int n = sqrt(c);
		for(int i = 0; i <= n; i++) {
			double a = sqrt(c - i * i);
			if(a - trunc(a) <= 1e-6)
				return true;
		}
		return false;
	}
};
// @lc code=end
