/**
����һ�������ж��������Ƿ��л���
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���

1����ϣ��
2������ָ��
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
			if(unMap[cur]){
				return true;
			}
			unMap[cur] = 1;
			cur = cur->next;
		}
		return false;
    }

	bool hasCycle_1(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return false;
		}


		ListNode* fast = head, *slot = head;

		while (fast != NULL)
		{
			if(!fast->next) return false;
			slot = slot->next;
			fast = fast->next->next;
			if (slot == fast) return true;
		}
		return false;
	}
};