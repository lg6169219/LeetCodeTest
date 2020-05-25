/**
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 示例 1:

 输入: a = "11", b = "1"
 输出: "100"
 示例 2:

 输入: a = "1010", b = "1011"
 输出: "10101"
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.length() == 0)
			return b;
		if (b.length() == 0)
			return a;

		string str = "";
		int maxLength = max(a.length(), b.length());
		while(a.length() < maxLength) //让两个字符串等长，若不等长，在短的字符串前补零，否则之后的操作会超出索引
		{
			a = '0' + a;
		}
		while(b.length() < maxLength)
		{
			b = '0' + b;
		}


		int flag = 0; // 进位标识
		for (int i = maxLength - 1; i >= 0; i--)
		{
			int sum = a[i] - '0' + b[i] - '0' + flag;
			a[i] = (sum) % 2+'0';//本位数值
			flag = sum / 2;//进位更新
		}

		if (flag == 1)
			a = '1' + a;

		return a;
	}
};