/**
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

*/

#include <iostream>
#include <unordered_map>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle_1(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return NULL;
		}
		ListNode *fast = head, *slow = head;

		while (fast!=NULL)
		{
			if (!fast->next) return NULL;

			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) return fast;
		}
		return NULL;
	}
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return NULL;
		}
		std::unordered_map<ListNode*, int> unMap;

		ListNode *cur = head;
		while (cur!=NULL)
		{
			if (unMap[cur])
			{
				return cur;
			}
			unMap[cur] = 1;
			cur = cur->next;
			
		}
		return NULL;
	}
};