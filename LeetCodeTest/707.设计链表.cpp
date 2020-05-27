/**
设计链表的实现。您可以选择使用单链表或双链表。
单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。
如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。
如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 

 示例：

 MyLinkedList linkedList = new MyLinkedList();
 linkedList.addAtHead(1);
 linkedList.addAtTail(3);
 linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
 linkedList.get(1);            //返回2
 linkedList.deleteAtIndex(1);  //现在链表是1-> 3
 linkedList.get(1);            //返回3
*/

#include <iostream>

struct LinkNode
{
	int val;
	LinkNode* next;
	LinkNode(int x):val(x),next(NULL){}
};

class MyLinkedList {
public:
	MyLinkedList(){
		head = NULL;
		len = 0;
	}
	~MyLinkedList(){}

	void addAtHead(int val){
		LinkNode* newNode = new LinkNode(val);
		if (head == NULL)
		{
			head = newNode;
		}else{
			newNode->next = head;
			head = newNode;
		}
		++len;
	}

	void addAtTail(int val){
		LinkNode* newNode = new LinkNode(val);
		if (head == NULL)
		{
			head = newNode;
		}else{
			// 找到尾部
			LinkNode* tail = head;
			while (tail->next != NULL )
			{
				tail = tail->next;
			}
			tail->next = newNode;
		}
		++len;
	}
	// 在链表中的第 index 个节点之前添加值为 val  的节点
	void addAtIndex(int index, int val){
		if (index < 0 || index > len)
			return;

		if (index == 0){
			addAtHead(val);
			return;
		}

		if (index == len){
			addAtTail(val);
			return;
		}

		LinkNode* newNode = new LinkNode(val);
		LinkNode* pre = head;

		// 找到index的前一个节点
		for (int i = 1; i < len; ++i)
		{
			if (i == index)
			{
				break;
			}
			pre = pre->next;
		}
		newNode->next = pre->next;
		pre->next = newNode;
		++len;
		return;
	}

	int get(int index){
		if (index < 0 || index > len - 1)
			return -1;
		
		LinkNode* cur = head;
		int curIndex = 0;
		while (cur != NULL)
		{
			if (curIndex == index){
				return cur->val;
			}
			++curIndex;
			cur = cur->next;
		}
		return -1;
	}

	void deleteAtIndex(int index){
		if (index < 0 || index > len - 1)
			return;

		if (index == 0){
			len--;
			head = head->next;
			return;
		}

		LinkNode* pre = head;

		int i = 0;
		while(pre&&i<index-1)
		{
			pre=pre->next;
			i++;
		}

		LinkNode* cur = pre->next;
		pre->next = cur->next;
		cur->next = NULL;
		len--;
		return;
	}
private:
	LinkNode* head;
	int len;
};


//************************* 双链表
struct LinkNode_Double
{
	int val;
	LinkNode_Double* next;
	LinkNode_Double* pre;
	LinkNode_Double(int x):val(x),next(NULL),pre(NULL){}
};

class MyLinkedList_Double {
public:
	MyLinkedList_Double(){
		head = NULL;
		len = 0;
	}
	~MyLinkedList_Double(){}

	void addAtHead(int val){
		LinkNode_Double* newNode = new LinkNode_Double(val);
		if (head == NULL)
		{
			head = newNode;
			tail = head;
		}else{
			head->pre = newNode;
			newNode->next = head;
			head = newNode;
		}
		++len;
	}

	void addAtTail(int val){
		LinkNode_Double* newNode = new LinkNode_Double(val);
		if (tail == NULL)
		{
			tail = newNode;
			head = tail;
		}else{
			// 找到尾部
			tail->next = newNode;
			newNode->pre = tail;
			tail = newNode;
		}
		++len;
	}
	// 在链表中的第 index 个节点之前添加值为 val  的节点
	void addAtIndex(int index, int val){
		if (index < 0 || index > len)
			return;

		if (index == 0){
			addAtHead(val);
			return;
		}

		if (index == len){
			addAtTail(val);
			return;
		}

		LinkNode_Double* newNode = new LinkNode_Double(val);
		LinkNode_Double* pre = head;

		// 找到index的前一个节点
		for (int i = 1; i < len; ++i)
		{
			if (i == index)
			{
				break;
			}
			pre = pre->next;
		}
		LinkNode_Double* cur = pre->next;

		newNode->next = cur;
		cur->pre = newNode;

		pre->next = newNode;
		newNode->pre = pre;

		++len;
		return;
	}

	int get(int index){
		int i = 0;
		LinkNode_Double* p = head;
		while (p&&i<index)
		{
			p = p->next;
			++i;
		}
		if (p) return p->val;
		else return -1;
	}

	void deleteAtIndex(int index){
		if(!head)return;
		if (index < 0 || index > len - 1)
			return;

		if (index == 0){
			LinkNode_Double* del = head;
			head = head->next;
			if(head){//链表有2个以上节点
				head->pre=NULL;
			}
			else{//链表只有一个节点，将尾部制空
				tail=NULL;
			}
			len--;
			return;
		}
		//index为最后为尾节点，我们需要删除尾节点
		if(index==len-1){
			LinkNode_Double *del=tail;
			tail=tail->pre;
			//注意这里不用处理tail为空，因为tail为空的话，那么链表只有单个节点
			//然而单个节点只能删除0号节点，只有index为0时才能删除，前面已经处理过了index为0的情况了，所以这里不在处理
			if(tail){
				tail->next=NULL;
			}
			delete del;
			len--;
			return;
		}

		LinkNode_Double* pre = head;

		int i = 0;
		while(pre&&i<index-1)
		{
			pre=pre->next;
			i++;
		}

		LinkNode_Double* cur = pre->next;
		pre->next = cur->next;
		cur->next->pre = pre;

		cur->next = NULL;
		cur->pre = NULL;
		delete cur;
		len--;
		return;
	}
private:
	LinkNode_Double *head, *tail;
	int len;
};