/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode-cn.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (71.09%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 13.8K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
 *
 * 示例 1:
 *
 * 输入: S = "ababcbacadefegdehijhklij"
 * 输出: [9,7,8]
 * 解释:
 * 划分结果为 "ababcbaca", "defegde", "hijhklij"。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 *
 *
 * 注意:
 *
 *
 * S的长度在[1, 500]之间。
 * S只包含小写字母'a'到'z'。
 *
 *
 */

// @lc code=start
class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector<int> ans;

		int le = 0;
		int ri = 0;
		int ll = S.size();
		for(int i = 0; i < ll; i++) {
			int tmp = S.find_last_of(S[i]);
			if(tmp > ri)
				ri = tmp;
			if(i == ri) {
				ans.push_back(ri - le);
				le = ri;
			}
		}
		ans[0]++;
		return ans;
	}
};
// @lc code=end
