/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

思路
	末位无进位，则末位加一即可，因为末位无进位，前面也不可能产生进位，比如 45 => 46
	末位有进位，在中间位置进位停止，则需要找到进位的典型标志，即为当前位 %10 后为 0，则前一位加 1，直到不为 0 为止，比如 499 => 500
	末位有进位，并且一直进位到最前方导致结果多出一位，对于这种情况，需要在第 2 种情况遍历结束的基础上，进行单独处理，比如 999 => 1000

	从末尾遍历 +1
	用一个flag表示进位flag=0/1
	注意首位数字进位时，原数组大小不足，导致越界
		解决办法
			一开始申请一个长度+1的数组保存新元素（可能导致内存浪费）
			或者在原数组计算，当首位需要进位时，才申请新的数组
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int flag = 1;
		vector<int> newList;
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			int val = flag + digits[i];
			flag = val >= 10 ? 1 : 0;
			digits[i] = val - 10 * flag;

			if (i == digits.size() - 1 && flag == 0)
			{
				return digits;
			}
		}

		// 首位进位的情况
		if (flag == 1)
		{
			digits[0] = 1;
			digits.push_back(0);
		}
		return digits;
	}
};