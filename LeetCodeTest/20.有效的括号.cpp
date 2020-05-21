#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/**
	思路
	每一个字符逐个入栈，入栈时需要判断和当前栈顶元素是否匹配，如果匹配就不入栈，同时将栈顶元素弹出栈，否则就入栈
	循环完成后，如果栈为空则返回true 否则false
*/
class Solution {
public:
	bool isEqual(char a, char b){
		bool equip = false;
		switch (a)
		{
		case '(':
			equip = (b == ')');
			break;
		case '[':
			equip = (b == ']');
			break;
		case '{':
			equip = (b == '}');
			break;
		default:
			equip = false;
			break;
		}
		return equip;
	}
	bool isValid(string s) {
		if (s.empty())
			return true;
		for (int i = 0; i < s.length(); ++i)
		{
			if (stk.empty())
			{
				stk.push(s[i]);
			}else{
				if (isEqual(stk.top(), s[i]))
				{
					stk.pop();
				}else{
					stk.push(s[i]);
				}
			}
		}
		return stk.empty();
	}
private:
	stack<char> stk;
};