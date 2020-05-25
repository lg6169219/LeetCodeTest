/**
给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

示例 1:

输入: [1,4,3,2]

输出: 4
解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
提示:

n 是正整数,范围在 [1, 10000].
数组中的元素范围在 [-10000, 10000].

思路
使得从1 到 n 的 min(ai, bi) 总和最大 就是对数据从小到大排序(让最大-最小的差值最小) 然后取2 2一组
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;       

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int totalNum = nums.size();
		if (totalNum <= 0)
			return 0;

		if (totalNum == 1)
			return nums[0];

		// 先排序
		sort(nums.begin(), nums.end());
		/*
		for (int i = 0; i < totalNum - 1; ++i)
		{
			// 一趟排序把最小的值放在i
			for (int j = i + 1; j < totalNum; ++j)
			{
				if (nums[i] > nums[j])
				{
					swap(nums[i], nums[j]);
				}
			}
		}*/

		int sum = 0;
		for (int i = 0; i < totalNum; i=i+2){
			sum += nums[i];
		}
		return sum;
	}
};