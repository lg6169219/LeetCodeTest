#include "1.两数之和.cpp"
#include "2.两数相加.cpp"

using namespace std;

int main(){
	/* 
	****************test01************
	Solution01* s01 = new Solution01();
	int a01[7] = {1,2,3,4,5,6,7};
	vector<int> it01;
	it01.insert(it01.begin(), a01, a01+8);
	int target01 = 9;

	vector<int> ret01 = s01->twoSum01(it01, 9);
	for (int i = 0; i < ret01.size(); ++i)
	{
		printf("=====test01  twoSum01  %d\n", ret01[i]);
	}
	ret01 = s01->twoSum02(it01, 9);
	for (int i = 0; i < ret01.size(); ++i)
	{
		printf("=====test01  twoSum02  %d\n", ret01[i]);
	}
	*/

	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	Solution02* s02 = new Solution02();
	ListNode* newList = s02->addTwoNumbers(l1, l2);
	ListNode* curNode = newList;
	while (curNode != NULL)
	{
		cout << curNode->val << endl;
		curNode = curNode->next;
	}
	delete curNode;
	
	system("pause");
	return 0;
}