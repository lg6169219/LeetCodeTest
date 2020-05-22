#include <iostream>
#include <stack>
#include <string>
#include <utility>
using namespace std;

/**
	���ȴ�������[]��Ҳ�����������ݣ�������ջ
	��Ҫ��������������ƴ���ַ���������ջ�����������Զ�Ӧ��
	s = "3[a]2[bc]", ���� "aaabcbc".
	s = "3[a2[c]]", ���� "accaccacc".
	s = "2[abc]3[cd]ef", ���� "abcabccdcdcdef".
*/

/**
	˼·
	ʹ��multi������ϵ����, res��ƴ�ӵ��ַ�����
	��������ջ stack�� �����ַ��� s ��ÿ���ַ� c��
		�� c Ϊ����ʱ���������ַ�ת��Ϊ���� multi�����ں����������㣻
		�� c Ϊ��ĸʱ���� res β����� c��
		�� c Ϊ [ ʱ������ǰ multi �� res ��ջ�����ֱ��ÿ��� 00��
			��¼�� [ ǰ����ʱ��� res ��ջ�����ڷ��ֶ�Ӧ ] ���ƴ�Ӳ�����
			��¼�� [ ǰ�ı��� multi ��ջ�����ڷ��ֶ�Ӧ ] �󣬻�ȡ multi �� [...] �ַ�����
			���뵽�� [ ��res �� multi ���¼�¼��
		�� c Ϊ ] ʱ��stack ��ջ��ƴ���ַ��� res = last_res + cur_multi * res������:
			last_res���ϸ� [ ����ǰ [ ���ַ��������� "3[a2[c]]" �е� a��
			cur_multi�ǵ�ǰ [ �� ] ���ַ������ظ����������� "3[a2[c]]" �е� 2��
		�����ַ��� res��
*/

class Solution {
public:
	string decodeString(string s) {
		stack<pair<int, string>> st;
		string res = "";
		string tempStr = "";
		int multi = 0;

		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ']') 
			{
				tempStr = "";
				pair<int, string> p = st.top();
				st.pop();
				for (int i = 0; i < p.first; ++i)
				{
					tempStr += res;
				}
				res = p.second + tempStr;
			}else if(s[i] == '['){
				st.push(make_pair(multi, res));
				multi = 0;
				res = "";
			}else if(s[i] >= '0' && s[i] <= '9'){
				multi = multi * 10 + s[i] - '0';  /**int('0') = 48*/
			}else{
				res += s[i];
			}
		}
		return res;
	}
};