/**
����һ�������ж��������Ƿ��л���
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���
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
    bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return false;
		}

		std::unordered_map<ListNode*, int> unMap;

		int pos = -1;
		ListNode* cur = head;
		while (cur != NULL)
		{

			cur = cur->next;
		}
    }
};