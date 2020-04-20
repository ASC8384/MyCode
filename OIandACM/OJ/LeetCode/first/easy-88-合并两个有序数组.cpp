/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
	// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
	// 	int pos = nums1.size() - 1;
	// 	m--;
	// 	n--;
	// 	while(n >= 0) {
	// 		nums1[pos--] = (m >= 0 && nums2[n] > nums1[m]) ? nums2[n--] : nums1[m--];
	// 	}
	// }
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
		int j = 0;
		for(int i = m; i <= n + m - 1; i++)
			nums1[i] = nums2[j++];
		sort(nums1.begin(), nums1.end());
	}
};
// @lc code=end
