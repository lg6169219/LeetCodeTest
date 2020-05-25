/**
485. 最大连续1的个数
给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,
1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：

输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		// 快慢指针
		

		int i = 0;
		int j = nums.size();
		if (j <= 0)
		{
			return 0;
		}
		int currNum = 0;
		int maxNum = 0;

		for (int i = 0; i < j; ++i)
		{
			if(nums[i] == 1){
				++currNum;
				maxNum = max(maxNum, currNum);
			}else{
				maxNum = max(maxNum, currNum);
				currNum = 0;
			}
		}
		return maxNum;
	}
};