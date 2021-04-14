/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (41.35%)
 * Likes:    1049
 * Dislikes: 0
 * Total Accepted:    133.4K
 * Total Submissions: 322.6K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 *
 *
 *
 * 示例 1:
 *
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 *
 *
 * 示例 2:
 *
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0];
        int minn = nums[0];
        int maxx = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            int tmax = maxx;
            int tmin = minn;
            maxx = max(tmax * nums[i], max(nums[i], tmin * nums[i]));
            minn = min(tmin * nums[i], min(nums[i], tmax * nums[i]));
            ret = max(ret, maxx);
        }
        return ret;
    }
};
// @lc code=end

