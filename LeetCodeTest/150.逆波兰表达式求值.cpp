/************************************************************************/
/* �沨��ʽ��Reverse Polish notation��RPN�����沨���Ƿ�����Ҳ�к�׺���ʽ���������д�ڲ�����֮��*/
/*
����: ["2", "1", "+", "3", "*"]
���: 9
����: ((2 + 1) * 3) = 9

����: ["4", "13", "5", "/", "+"]
���: 6
����: (4 + (13 / 5)) = 6
*/
/*
	˼·
	�����ջ
		�����ջ���Ƿ��ţ���ջ�е�������Ԫ�أ���һ��Ԫ���ڷ����Ҳ࣬�ڶ�����������࣬�������㣬����������ջ
		�����ջ���ǷǷ��ţ���ֵ����������ջ
	ֱ��ջΪ1
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