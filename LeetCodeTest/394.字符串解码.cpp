#include <iostream>
#include <stack>
#include <string>
#include <utility>
using namespace std;

/**
	优先处理最后的[]，也就是最后的数据，所以用栈
	需要从内向外生成与拼接字符串，这与栈的先入后出特性对应。
	s = "3[a]2[bc]", 返回 "aaabcbc".
	s = "3[a2[c]]", 返回 "accaccacc".
	s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
*/

/**
	思路
	使用multi（数字系数）, res（拼接的字符串）
	构建辅助栈 stack， 遍历字符串 s 中每个字符 c；
		当 c 为数字时，将数字字符转化为数字 multi，用于后续倍数计算；
		当 c 为字母时，在 res 尾部添加 c；
		当 c 为 [ 时，将当前 multi 和 res 入栈，并分别置空置 00：
			记录此 [ 前的临时结果 res 至栈，用于发现对应 ] 后的拼接操作；
			记录此 [ 前的倍数 multi 至栈，用于发现对应 ] 后，获取 multi × [...] 字符串。
			进入到新 [ 后，res 和 multi 重新记录。
		当 c 为 ] 时，stack 出栈，拼接字符串 res = last_res + cur_multi * res，其中:
			last_res是上个 [ 到当前 [ 的字符串，例如 "3[a2[c]]" 中的 a；
			cur_multi是当前 [ 到 ] 内字符串的重复倍数，例如 "3[a2[c]]" 中的 2。
		返回字符串 res。
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