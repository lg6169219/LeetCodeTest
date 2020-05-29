/**
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

思路 删除节点需要保存这个节点的前一个节点 所以用双指针
难点是如何处理删除的节点在头部的情况
可以通过哨兵节点去解决它，哨兵节点广泛应用于树和链表中，如伪头、伪尾、标记等，它们是纯功能的，通常不保存任何数据，其主要目的是使链表标准化，如使链表永不为空、永不无头、简化插入和删除。
*/

#include <iostream>

struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	// 链表 一定要画图
	ListNode* removeElements(ListNode* head, int val) {
		if(head == NULL)
			return NULL;

		ListNode* sentinel = new ListNode(0); // 哨兵节点
		sentinel->next = head;

		ListNode* cur = head;
		ListNode* pre = sentinel;
		ListNode* del = NULL;


		while (cur != NULL)
		{
			if (cur->val == val)
			{
				del = cur;
				pre->next = cur->next;
			}else{
				pre = cur;
			}
			cur = cur->next;
			if (del)
			{
				delete del;
				del = NULL;
			}
		}

		head = sentinel->next;

		delete sentinel;
		sentinel = NULL;

		return head;
	}

	// 递归
	// 终止条件是节点为null，
	// 然后一层一层的调用，到最后终止条件时返回，
	// 判断当前节点的直是否为要删除直，
	// 如果是，则返回当前节点的下一节点，不返回当前节点就是删除当前节点，
	// 如果不是，则返回当前节点。
	ListNode* removeElements_1(ListNode* head, int val) {
		if (head == NULL) return NULL;
		head->next = removeElements_1(head->next, val);
		return head->val == val ? head->next : head;
	}
};