/**
ʹ�ö���ʵ��ջ�����в�����
	push(x) -- Ԫ�� x ��ջ
	pop() -- �Ƴ�ջ��Ԫ��
	top() -- ��ȡջ��Ԫ��
	empty() -- ����ջ�Ƿ�Ϊ��

	˼·
	��������
	final���еĶ�ͷʼ�մ��ջ����Ԫ��
	Ԫ�ؽ�ջ == ��final������Ԫ�س��Ӵ���temp�У�Ԫ�ط���final��ͷ��tempԪ�����������final

	1������
	ѭ������
	Ԫ����ջ����Ԫ��֮ǰ��Ԫ��������ӣ�����ӣ����������������к��ջ
*/

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		while(!finalQue.empty()){
			tempQue.push(finalQue.front());
			finalQue.pop();
		}
		finalQue.push(x);

		while(!tempQue.empty()){
			finalQue.push(tempQue.front());
			tempQue.pop();
		}
	}

	void push2(int x) {
		finalQue.push(x);
		for (int i = 0; i < finalQue.size() - 1; ++i)
		{
			finalQue.push(finalQue.front());
			finalQue.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		auto val = finalQue.front();
		finalQue.pop();
		return val;
	}

	/** Get the top element. */
	int top() {
		return finalQue.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return finalQue.size() == 0;
	}
private:
	queue<int> tempQue;
	queue<int> finalQue;
};