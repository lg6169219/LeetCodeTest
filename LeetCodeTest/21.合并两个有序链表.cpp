/**
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

 示例：

 输入：1->2->4, 1->3->4
 输出：1->1->2->3->4->4

思路
	1、用c++的stl 将链表变成数组
	2、暴力解法 创建一个新的头节点，pre执行这个头结点，每次从l1 l2中找出最小值pre.next =  最小值 pre = pre.next
	3、递归
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
		{
			return l2;
		}else if (l2 == NULL)
		{
			return l1;
		}

		ListNode *preHead = new ListNode(-1);

		ListNode *pre = preHead;

		while (l1 && l2)
		{
			if(l1->val < l2->val){
				pre->next = l1;
				l1 = l1->next;
			}else{
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next;
		}

		 // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
		pre->next = l1 ? l1 : l2;

		ListNode *ret = preHead->next;
		delete preHead;
		return ret;
	}

	ListNode* mergeTwoLists_1(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
		{
			return l2;
		}else if (l2 == NULL)
		{
			return l1;
		}else if(l1->val < l2->val){
			l1->next = mergeTwoLists_1(l1->next, l2);
			return l1;
		}else{
			l2->next = mergeTwoLists_1(l2->next, l1);
			return l2;
		}	
	}
};