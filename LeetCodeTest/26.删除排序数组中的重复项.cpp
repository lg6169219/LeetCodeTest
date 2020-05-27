/**
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。



示例 1:

给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。

思路
用快慢指针
一个current指针（当前对比指针），依次往后
一个find指针，找到第一个与current不相等的值的位置，放到current位置上
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.size() <= 1){
			return nums.size();
		}
		int current = 0;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] != nums[current])
			{
				current++;
				nums[current] = nums[i];
			}
		}
		return current + 1;
	}
};