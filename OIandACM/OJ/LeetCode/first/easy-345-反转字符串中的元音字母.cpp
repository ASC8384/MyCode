/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
	string reverseVowels(string s) {
		deque<int> a;

		int ll = s.length();
		for(int i = 0; i < ll; i++) {
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
				a.push_back(i);
			}
		}
		while(a.size() > 1) {
			swap(s[a.front()], s[a.back()]);
			a.pop_back();
			a.pop_front();
		}
		return s;
	}
};
// @lc code=end
