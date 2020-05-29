/**
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)(使用常量个变量)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

思路
创建一个新的头结点 将链表拆为奇偶两列 最后合并
类似删除奇数的算法，只不过这里是把奇数保存到另外的head
(思考 是把奇数拿出来还是偶数？ 因为奇数在前偶数在后 奇数的尾巴+偶数的头，所以把奇数节点拿出来)
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
		// 创建一个哨兵节点
		ListNode* shaobing = new ListNode;
		shaobing->next = head;

		ListNode* newHead = head; // 保存新的链表头部
		ListNode* newTail = head; // 保存新的链表尾部

		ListNode* pre = shaobing;
		ListNode* cur = shaobing->next;

		ListNode* del = nullptr;

		int i = 1;

		while(cur != NULL){
			if(i % 2 != 0){
				// 奇数 放入新数组 (相当于删除这个节点)
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