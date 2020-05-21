/************************************************************************/
/* 逆波兰式（Reverse Polish notation，RPN，或逆波兰记法），也叫后缀表达式（将运算符写在操作数之后）*/
/*
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
*/
/*
	思路
	逐个入栈
		如果入栈的是符号，从栈中弹出两个元素，第一个元素在符号右侧，第二个符号在左侧，进行运算，将运算结果入栈
		如果入栈的是非符号（数值），正常入栈
	直到栈为1
*/
/************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isSign(string str){
		if(str.compare("+") == 0 || str.compare("-") == 0 || str.compare("*") == 0 || str.compare("/") == 0){
			return true;
		}
		return false;
	}
	int operation(string str, int a, int b){
		if(str.compare("+") == 0){
			return a + b;
		} else if (str.compare("-") == 0){
			return a - b;
		} else if(str.compare("*") == 0){
			return a * b;
		}else if(str.compare("/") == 0){
			return a / b;
		} 
		return 0;
	}
	int evalRPN(vector<string>& tokens) {
		stack<string> st;
		for (int i = 0; i < tokens.size(); ++i)
		{
			if (isSign(tokens[i])){
				int a = atoi(st.top().c_str());
				st.pop();
				int b = atoi(st.top().c_str());
				st.pop();
				int val = operation(tokens[i], b, a);
				st.push(to_string(val));
			}else{
				st.push(tokens[i]);
			}
		}
		return atoi(st.top().c_str());
	}
};