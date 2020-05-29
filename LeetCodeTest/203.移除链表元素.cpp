/**
ɾ�������е��ڸ���ֵ val �����нڵ㡣

ʾ��:

����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5

˼· ɾ���ڵ���Ҫ��������ڵ��ǰһ���ڵ� ������˫ָ��
�ѵ�����δ���ɾ���Ľڵ���ͷ�������
����ͨ���ڱ��ڵ�ȥ��������ڱ��ڵ�㷺Ӧ�������������У���αͷ��αβ����ǵȣ������Ǵ����ܵģ�ͨ���������κ����ݣ�����ҪĿ����ʹ�����׼������ʹ��������Ϊ�ա�������ͷ���򻯲����ɾ����
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
	// ���� һ��Ҫ��ͼ
	ListNode* removeElements(ListNode* head, int val) {
		if(head == NULL)
			return NULL;

		ListNode* sentinel = new ListNode(0); // �ڱ��ڵ�
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

	// �ݹ�
	// ��ֹ�����ǽڵ�Ϊnull��
	// Ȼ��һ��һ��ĵ��ã��������ֹ����ʱ���أ�
	// �жϵ�ǰ�ڵ��ֱ�Ƿ�ΪҪɾ��ֱ��
	// ����ǣ��򷵻ص�ǰ�ڵ����һ�ڵ㣬�����ص�ǰ�ڵ����ɾ����ǰ�ڵ㣬
	// ������ǣ��򷵻ص�ǰ�ڵ㡣
	ListNode* removeElements_1(ListNode* head, int val) {
		if (head == NULL) return NULL;
		head->next = removeElements_1(head->next, val);
		return head->val == val ? head->next : head;
	}
};