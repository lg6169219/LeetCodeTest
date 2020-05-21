/**
使用队列实现栈的下列操作：
	push(x) -- 元素 x 入栈
	pop() -- 移除栈顶元素
	top() -- 获取栈顶元素
	empty() -- 返回栈是否为空

	思路
	两个队列
	final队列的队头始终存放栈顶的元素
	元素进栈 == 将final的所有元素出队存入temp中，元素放入final队头，temp元素再逐个进队final

	1个队列
	循环队列
	元素入栈，将元素之前的元素逐个出队，再入队，这样就是重新排列后的栈
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