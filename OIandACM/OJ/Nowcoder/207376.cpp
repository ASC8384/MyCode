class Solution {
public:
	/**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求最小差值
     * @param a int整型vector 数组a
     * @return int整型
     */
	int minDifference(vector<int> &a) {
		sort(a.begin(), a.end());
		int		  n	  = a.size();
		long long ans = abs(a[1] - a[0]);
		for(int i = 1; i < n; i++)
			ans = min(ans, abs((long long)a[i] - (long long)a[i - 1]));
		return ans;
	}
};