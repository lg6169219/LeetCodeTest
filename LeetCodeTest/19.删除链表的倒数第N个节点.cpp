/**
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

1、先一趟遍历找到长度，再一趟找倒数第几个
2、倒数第2 那么这个节点的.next.next为空，倒数第n个就是n个。next后为空
进阶：

你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
			return head;
        
		ListNode* cur = head;
		ListNode* temp = head;
		int num = 0;
		while (cur!=NULL)
		{
			temp = cur;
			int i = 0;
			for (i = 0; i < n + 1 && temp != NULL; ++i)
			{
				temp = temp->next;
			}
			if (temp == NULL && i == n + 1)
			{
				ListNode* delNode = cur->next;
				cur->next = cur->next->next;
				delNode->next = NULL;
				return head;
			}
			num++;
			cur = cur->next;
		}
		// 删除的是头节点
		if (num == n){
			head = head->next;
			return head;
		}
		return NULL;
    }
};