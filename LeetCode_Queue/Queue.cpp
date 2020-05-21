#include <iostream>
#include <vector>
using namespace std;

class MyQueue
{
public:
	MyQueue(){p_start=0;}
	~MyQueue(){}
	bool enQueue(int x){
		data.push_back(x);
		return true;
	}
	/**
	* 头指针后移 低效导致前面出队的内存浪费
	* 优化方法使用循环队列。 具体来说，我们可以使用固定大小的数组和两个指针来指示起始位置和结束位置。 目的是重用我们之前提到的被浪费的存储。
	*/
	bool deQueue(){
		if (isEmpty()){
			return false;
		}
		p_start++;
		return true;
	}

	int Front(){
		return data[p_start];
	}

	bool isEmpty(){
		return p_start >= data.size();
	}
private:
	vector<int> data;
	int p_start;
};

int main_MyQueue(){
	MyQueue q;
	q.enQueue(5);
	q.enQueue(3);
	if (!q.isEmpty()) {
		cout << q.Front() << endl;
	}
	q.deQueue();
	if (!q.isEmpty()) {
		cout << q.Front() << endl;
	}
	q.deQueue();
	if (!q.isEmpty()) {
		cout << q.Front() << endl;
	}

	return 0;
}