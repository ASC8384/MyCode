/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (37.63%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    119.3K
 * Total Submissions: 316.9K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 *
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 *
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 *
 * 示例 1:
 *
 * 输入: 4
 * 输出: 2
 *
 *
 * 示例 2:
 *
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842...,
 * 由于返回类型是整数，小数部分将被舍去。
 *
 *
 */

// @lc code=start
class Solution {
public:
	int mySqrt(int x) {
		if(x <= 1)
			return x;
		double ll = 1.0;
		double ri = x / 2.0 + 1.0;
		while(ri - ll >= 1e-6) {
			double mid = (ri + ll) / 2.0;
			double tmp = mid * mid;
			if(tmp == x) {
				return (int)mid;
			} else if(tmp > x) {
				ri = mid;
			} else {
				ll = mid;
			}
		}
		return (int)ri;
	}
};
// @lc code=end
