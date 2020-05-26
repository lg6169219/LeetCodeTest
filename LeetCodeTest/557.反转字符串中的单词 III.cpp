/**
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

1、自己实现split
2、用栈
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	vector<string> split(const string& s, const char* c)
	{
		vector<string> v;
		int len = s.size();

		char *p = new char[len + 1];
		strcpy(p, s.c_str());

		// 分解字符串为一组字符串。p为要分解的字符串 c为分隔符
		char* tok = strtok(p, c);
		while(tok){
			string tmp(tok);
			v.push_back(tmp);
			tok = strtok(NULL, c);
		}

		delete [] p;
		return v;
	}
	vector<string> split(const string& s, const char* c){
		vector<string> v;
		int len = s.size();

		char *p = new char[len + 1];
		strcpy(p, s.c_str());

		char* tok = strtok(p, c);
		while (tok)
		{
			string tmp(tok);
			v.push_back(tmp);
			tok = strtok(NULL, c);
		}

		delete [] p;
		return v;
	}
	string reverseWords(string s) {
		if(s == "")
			return s;

		string ret;
		vector<string> sVec = split(s, " ");
		for (aotu& i : v)
		{
			reverse(i.begin(), i.end());
			ret += i + " ";
		}
		ret.erase(ret.end() - 1);
		return ret;
	}

	string reverseWords_1(string s) {
		if(s == "")
			return s;

		stack<char> st;
		string ret;

		for (auto c:s)
		{
			if (c == ' '){
				while (!st.empty())
				{
					ret += st.top();
					st.pop();
				}
				ret += ' ';
			}else{
				st.push(c);
			}
		}
		while (!st.empty())
		{
			ret += st.top();
			st.pop();
		}
		return ret;
	}
};