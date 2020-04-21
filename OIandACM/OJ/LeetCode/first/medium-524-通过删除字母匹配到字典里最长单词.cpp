/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
	static bool cmp(string a, string b) {
		if(a.size() > b.size())
			return true;
		else if(a.size() < b.size())
			return false;
		else
			return a < b;
	}

	string findLongestWord(string s, vector<string> &d) {
		sort(d.begin(), d.end(), cmp);
		//cout << d[0] << " " << d[1] << " " << d[2]<< endl;
		int n = d.size();
		for(int i = 0; i < n; i++) {
			int	 ll	  = d[i].size();
			bool flag = true;
			int	 k	  = 0;
			for(int j = 0; j < ll; j++) {
				if((k = s.find(d[i][j], k)) != string::npos) {
					k++;
				} else {
					flag = false;
					break;
				}
			}
			if(flag) {
				return d[i];
			}
		}
		return "";
	}
};
/*
"aaa"
["aaa","aa","a"]
"abpcplea"
["ale","apple","monkey","plea"]
*/
// @lc code=end
