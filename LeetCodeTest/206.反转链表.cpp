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
	// ����
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		ListNode* cur = head->next;
		ListNode* movNode = NULL;
		// ��ͷ���ȡ����nextָ��NULL
		head->next = NULL;

		while (cur != NULL)
		{
			movNode = cur;
			cur = cur->next;
			movNode->next = head;
			head = movNode;
		}
		return head;
	}

};