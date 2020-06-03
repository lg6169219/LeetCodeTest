/**
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

 示例：

 输入：1->2->4, 1->3->4
 输出：1->1->2->3->4->4

思路
	1、暴力解法 创建一个新的头节点，pre执行这个头结点，每次从l1 l2中找出最小值pre.next =  最小值 pre = pre.next
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
		}
		if (l2 == NULL)
		{
			return l1;
		}


		// 新的伪节点
		ListNode *temp1 = new ListNode;
		ListNode *pre = temp1;


		ListNode *temp2 = new ListNode;
		temp1->next = l1;
		temp2->next = l2;

		ListNode *pre1 = temp1, *pre2 = temp2 ;
		ListNode *cur1 = l1, *cur2 = l2;
		// 把cur2插入到cur1
		while (cur2 && cur1)
		{
			if (cur2->val <= cur1->val)
			{
				pre2->next = cur2->next;

				cur2->next = cur1;
				pre1->next = cur2;
				pre1 = cur2;
			}else{
				pre1 = cur1;
				cur1 = cur1->next;
			}
			cur2 = cur2->next;
		}

		if (cur2)
		{
			cur1->next = cur2;
			pre2->next = NULL;
		}

		ListNode *ret = temp1->next;
		delete temp1;
		delete temp2;
		return ret;
	}
};


int main(){
	ListNode *l1{1, 2, 4};
	ListNode *l2{1, 3, 4};

	return 0;
}