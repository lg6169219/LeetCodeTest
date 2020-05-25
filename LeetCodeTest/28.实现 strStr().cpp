#include <iostream>
#include <vector>
#include <string>
/**
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == "")
		{
			return 0;
		}

		char str = needle[0];
		int index = -1;
		int sameNum = 0;

		int length1 = haystack.length();
		int length2 = needle.length();
		for (int j = 0; j < length1 - length2 + 1; ++j)
		{
			if (str == haystack[j]) // 找到和头相等文件 就扫一遍needle看看是不是全等
			{
				sameNum = 0;
				++sameNum;
				for (int i = 1; i < length2; ++i)
				{
					if (haystack[j + i] == needle[i]){
						++sameNum;
					}else{
						break;
					}
				}
				// 扫完比较一下
				if (sameNum == length2){
					index = j;
					break;
				}
			}
		}
		return index;
	}
};