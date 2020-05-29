/**
��תһ��������

ʾ��:

����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL
����:
����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// ���� ˫ָ��
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		ListNode* cur = NULL;
		ListNode* next = head;
		ListNode* t = NULL;

		while (next != NULL)
		{
			t = next->next;
			next->next = cur; 
			cur = next;
			next = t;
		}
		return cur;
	}

	// �ݹ�
	ListNode* reverseList_1(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		ListNode* ret = reverseList_1(head->next);

		head->next->next = head;
		head->next = NULL;
		
		return ret;
	}
};