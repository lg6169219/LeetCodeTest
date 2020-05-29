/**
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�

�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)(ʹ�ó���������)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������

ʾ�� 1:

����: 1->2->3->4->5->NULL
���: 1->3->5->2->4->NULL
ʾ�� 2:

����: 2->1->3->5->6->4->7->NULL 
���: 2->3->6->7->1->5->4->NULL
˵��:

Ӧ�����������ڵ��ż���ڵ�����˳��
����ĵ�һ���ڵ���Ϊ�����ڵ㣬�ڶ����ڵ���Ϊż���ڵ㣬�Դ����ơ�

˼·
����һ���µ�ͷ��� �������Ϊ��ż���� ���ϲ�
����ɾ���������㷨��ֻ���������ǰ��������浽�����head
(˼�� �ǰ������ó�������ż���� ��Ϊ������ǰż���ں� ������β��+ż����ͷ�����԰������ڵ��ó���)
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
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == NULL) return head;
		// ����һ���ڱ��ڵ�
		ListNode* shaobing = new ListNode;
		shaobing->next = head;

		ListNode* newHead = head; // �����µ�����ͷ��
		ListNode* newTail = head; // �����µ�����β��

		ListNode* pre = shaobing;
		ListNode* cur = shaobing->next;

		ListNode* del = nullptr;

		int i = 1;

		while(cur != NULL){
			if(i % 2 != 0){
				// ���� ���������� (�൱��ɾ������ڵ�)
				del = cur;
				pre->next = cur->next;
			}else{
				pre = cur;
			}

			cur = cur->next;

			if (del != nullptr)
			{
				del->next = NULL;
				if (newTail != del){
					newTail->next = del;
					newTail = del;
				}
				del = nullptr;
			}
			++i;
		}
		newTail->next = shaobing->next;

		delete shaobing;

		return newHead;
	}
};