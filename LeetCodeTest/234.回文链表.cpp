/**
请判断一个链表是否为回文链表。

回文 1-a-a-1 

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

思路
1、把链表内容复制到数组，用双指针从头和尾遍历
2、我们可以将链表的后半部分反转（修改链表结构），然后将前半部分和后半部分进行比较。
	比较完成后我们应该将链表恢复原样。虽然不需要恢复也能通过测试用例，因为使用该函数的人不希望链表结构被更改。
	算法：
	我们可以分为以下几个步骤：

	找到前半部分链表的尾节点。
	反转后半部分链表。
	判断是否为回文。
	恢复链表。
	返回结果。

这一题的心得
把复杂的问题拆解成一个个简单的问题，求解
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode():val(0),next(nullptr){};
	ListNode(int x):val(x),next(nullptr){};
	ListNode(int x, ListNode *next):val(x),next(next){};
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL) return true;
		// 1、快慢指针找中点
		ListNode *fast = head, *slow = head, *pre = nullptr;
		while (fast&&fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		// 2、分成2个链表 并且将后面的链表翻转
		while (slow)
		{
			ListNode *p = slow->next;
			slow->next = pre;
			pre = slow;
			slow = p;
		}

		// 3、前后链表进行比较，注意若为奇数链表，后半部分回比前部分多1一个节点，然而我们只比较相同长度的节点值，巧妙地避开这点判断
		while (head&&pre)
		{
			if(head->val!=pre->val)return false;
			head = head->next;
			pre = pre->next;
		}
		return true;
	}
};