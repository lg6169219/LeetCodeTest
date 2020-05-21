/**
	使用栈模拟队列
	用到两个栈，用它们其中一个来反转元素的入队顺序，用另一个来存储元素的最终顺序。
	栈顶是队头，栈底是队尾
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
			/**把数组逐个放入temp中，再把新数据放在最下面*/
			while (!finalStack.empty())
			{
				tempStack.push(finalStack.top());
				finalStack.pop();
			}
			/**新元素放入栈底*/
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