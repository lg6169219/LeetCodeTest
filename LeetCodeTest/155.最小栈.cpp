#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		data.clear();
		mindata.clear();
		mindata.push_back(INT_MAX);
	}

	void push(int x) {
		data.push_back(x);
		mindata.push_back(min(mindata.back(), x));
	}


	void pop() {
		data.pop_back();
		mindata.pop_back();
		return;
	}

	int top() {
		return data.back();
	}

	int getMin() {
		return mindata.back();
	}
private:
	vector<int> data;
	vector<int> mindata;
};

class MinStack_UseStack {
	stack<int> x_stack;
	stack<int> min_stack;
public:
	MinStack_UseStack() {
		min_stack.push(INT_MAX);
	}

	void push(int x) {
		x_stack.push(x);
		min_stack.push(min(min_stack.top(), x));
	}

	void pop() {
		x_stack.pop();
		min_stack.pop();
	}

	int top() {
		return x_stack.top();
	}

	int getMin() {
		return min_stack.top();
	}
};