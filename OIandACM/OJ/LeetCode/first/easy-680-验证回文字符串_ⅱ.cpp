/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start

class Solution {
public:
	bool is(int le, int ri, string &s) {
		if(le == ri)
			return true;
		while(le < ri) {
			if(s[le] != s[ri]) {
				return false;
			} else {
				le++;
				ri--;
			}
		}
		return true;
	}

	bool validPalindrome(string s) {
		int ll = s.size();
		int le = 0, ri = ll - 1;
		if(le == ri)
			return true;
		while(le < ri) {
			if(s[le] != s[ri]) {
				return (is(le + 1, ri, s) || is(le, ri - 1, s));
			} else {
				le++;
				ri--;
			}
		}
		return true;
		//return is(0, ll - 1, s);
	}
};
// @lc code=end
