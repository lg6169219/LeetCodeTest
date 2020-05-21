#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue
{
public:
	MyCircularQueue(int k){
		this->data.resize(k);
		size = k;
		head = -1;
		tail = -1;
	}
	~MyCircularQueue(){

	}

	/** 入队*/
	bool enQueue(int value){
		if(isFull()){
			return false;
		}
		if (isEmpty())
		{
			head = 0;
		}
		tail = (tail + 1) % size;
		data[tail] = value;
		return true;
	}

	/** 出队*/
	bool deQueue(){
		if(isEmpty()){
			return false;
		}
		if (head == tail)
		{
			head = -1;
			tail = -1;
			return true;
		}
		head = (head + 1) % size;
		return true;
	}

	int Front(){
		if (isEmpty()) {
			return -1;
		}
		return data[head];
	}

	int Rear(){
		if (isEmpty()) {
			return -1;
		}
		return data[tail];
	}

	bool isEmpty(){
		return head == -1;
	}

	bool isFull(){
		return (((tail + 1) % size) == head);
	}

private:
	vector<int> data;
	int head;
	int tail;
	int size;
};

int main_MyCircularQueue(){

	MyCircularQueue* obj = new MyCircularQueue(5);
	bool param_1 = obj->enQueue(1);
	bool param_11 = obj->enQueue(2);
	bool param_2 = obj->deQueue();
	int param_3 = obj->Front();
	int param_4 = obj->Rear();
	bool param_5 = obj->isEmpty();
	bool param_6 = obj->isFull();
	cout << param_1 << param_2 << param_3 << param_4 << param_5 << param_6 << endl;

	system("pause");
	return 0;
}