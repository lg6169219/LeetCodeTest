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
	* ͷָ����� ��Ч����ǰ����ӵ��ڴ��˷�
	* �Ż�����ʹ��ѭ�����С� ������˵�����ǿ���ʹ�ù̶���С�����������ָ����ָʾ��ʼλ�úͽ���λ�á� Ŀ������������֮ǰ�ᵽ�ı��˷ѵĴ洢��
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