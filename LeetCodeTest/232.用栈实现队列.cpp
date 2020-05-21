/**
	ʹ��ջģ�����
	�õ�����ջ������������һ������תԪ�ص����˳������һ�����洢Ԫ�ص�����˳��
	ջ���Ƕ�ͷ��ջ���Ƕ�β
*/
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
		
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
		if (empty())
		{
			finalStack.push(x);
		}else{
			/**�������������temp�У��ٰ������ݷ���������*/
			while (!finalStack.empty())
			{
				tempStack.push(finalStack.top());
				finalStack.pop();
			}
			/**��Ԫ�ط���ջ��*/
			finalStack.push(x);
			while (!tempStack.empty())
			{
				finalStack.push(tempStack.top());
				tempStack.pop();
			}
		}
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		auto val = finalStack.top();
		finalStack.pop();
		return val;
    }
    
    /** Get the front element. */
    int peek() {
		return finalStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return finalStack.size() == 0;
    }
private:
	stack<int> tempStack;
	stack<int> finalStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */