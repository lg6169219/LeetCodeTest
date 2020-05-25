/**
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

所有输入只包含小写字母 a-z 。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int size = strs.size();
		if (size == 0){
			return "";
		}
		if (size == 1){
			return strs[0];
		}

		// 先一趟找到最小长度
		int minLength = INT_MAX;
		for (int i = 0; i < size; ++i)
		{
			minLength = min(minLength, (int)strs[i].length());
		}

		string reStr = "";
		for (int i = 0; i < minLength; ++i)
		{
			char str = strs[0][i];
			for (int j = 0; j < size; ++j)
			{
				if(!(str == strs[j][i])){
					return reStr;
				}
			}
			reStr += str;
		}
		return reStr;
	}
};