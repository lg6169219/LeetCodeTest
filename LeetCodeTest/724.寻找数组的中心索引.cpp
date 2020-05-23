/**
输入: 
nums = [1, 7, 3, 6, 5, 6]
输出: 3
解释: 
索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
同时, 3 也是第一个符合要求的中心索引。

思路
数组长度小于3 返回-1
计算数组元素之和sum
从第0个元素开始遍历，计算左侧的和 右侧和=sum-左侧的和-本元素

注意临界值 pos = 0 或者为length-1
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int numsSize = nums.size();
		int pos = -1;
		if (numsSize <= 0)
			return pos;

		int sum = 0;
		for (int i = 0; i < numsSize; ++i)
		{
			sum += nums[i];
		}

		int leftSum = 0;
		for (int i = 0; i < numsSize; ++i)
		{
			leftSum += nums[i];
			if (leftSum == sum - leftSum + nums[i])
			{
				pos = i;
				break;
			}
		}
		return pos;
	}
};