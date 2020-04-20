/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *		pos = head;
		set<ListNode *> a;
		int				cnt = 0;
		while(pos) {
			a.insert(pos);
			if(cnt == a.size()) {
				return true;
			}
			pos = pos->next;
			cnt = a.size();
		}
		return false;
	}
};
// @lc code=end
