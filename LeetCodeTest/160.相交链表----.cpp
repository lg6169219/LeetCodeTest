/**
编写一个程序，找到两个单链表相交的起始节点。
1、哈希表
2、暴力遍历对比法
3、双指针
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)
		{
			return NULL;
		}
		std::unordered_map<ListNode*, int> unMap;

		ListNode* cur = headA;
		while(cur!=NULL){
			unMap[cur] = 1;
			cur = cur->next;
		}

		cur = headB;
		while(cur!=NULL){
			if (unMap[cur]){
				return cur;
			}
			unMap[cur] = 1;
			cur = cur->next;
		}
		return NULL;
	}

	ListNode *getIntersectionNode_1(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)
		{
			return NULL;
		}
		
		ListNode *cur_a = headA, *cur_b = headB;
		while(cur_a != cur_b){
			cur_a = (cur_a == NULL) ? headB : cur_a->next;
			cur_b = (cur_b == NULL) ? headA : cur_b->next;
		}

		return cur_a;
	}
};