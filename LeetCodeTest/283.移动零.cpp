/**
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

思路
用双指针把非零数挪到前面，再把后面的数赋值为0
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() <= 1)
		{
			return;
		}

		int current = 0;
		for (int i = 0; i < nums.size(); ++i){
			if (nums[i] == 0)
			{
				current = i;
				break;
			}
		}

		for (int i = current + 1; i < nums.size(); ++i)
		{
			if (nums[current] == 0 && nums[i] != nums[current])
			{
				nums[current] = nums[i];
				nums[i] = 0;
				current++;
			}
		}
		return;
	}
};

