#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/**
	˼·
	ÿһ���ַ������ջ����ջʱ��Ҫ�жϺ͵�ǰջ��Ԫ���Ƿ�ƥ�䣬���ƥ��Ͳ���ջ��ͬʱ��ջ��Ԫ�ص���ջ���������ջ
	ѭ����ɺ����ջΪ���򷵻�true ����false
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