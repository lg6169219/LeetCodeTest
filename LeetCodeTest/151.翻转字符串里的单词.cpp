/**
给定一个字符串，逐个翻转字符串中的每个单词。
 示例 1：

 输入: "the sky is blue"
 输出: "blue is sky the"
 示例 2：

 输入: "  hello world!  "
 输出: "world! hello"
 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 示例 3：

 输入: "a good   example"
 输出: "example good a"
 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
  
  说明：

  无空格字符构成一个单词。
  输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
  如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		if (s == "")
			return "";

		stack<string> st;
		char k = ' ';
		string temp = "";
		for (int i = 0; i < s.length(); ++i)
		{
			if(s[i] == k){
				if(temp == ""){
					continue;
				}else{
					// 入栈
					st.push(temp);
					temp = "";
				}
			}else{
				//拼接
				temp += s[i];
			}
		}
		if (temp != "")
			st.push(temp);

		temp = "";
		while(!st.empty()){
			temp += st.top();
			st.pop();
			if(!st.empty())
				temp += " ";
		}

		return temp;
	}

	string reverseWords_1(string s) {
		// 反转整个字符串
		reverse(s.begin(), s.end());

		int n = s.size();
		int idx = 0;
		for (int start = 0; start < n; ++start) {
			if (s[start] != ' ') {
				// 填一个空白字符然后将idx移动到下一个单词的开头位置
				if (idx != 0) s[idx++] = ' ';

				// 循环遍历至单词的末尾
				int end = start;
				while (end < n && s[end] != ' ') s[idx++] = s[end++];

				// 反转整个单词
				reverse(s.begin() + idx - (end - start), s.begin() + idx);

				// 更新start，去找下一个单词
				start = end;
			}
		}
		s.erase(s.begin() + idx, s.end());
		return s;
	}
};