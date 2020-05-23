#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

/**
输入: nums = [3, 6, 1, 0]
输出: 1
解释: 6是最大的整数, 对于数组中的其他整数,
6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
*/
class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int maxNum = INT_MIN;
		int maxNumIndex = -1;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > maxNum)
			{
				maxNum = nums[i];
				maxNumIndex = i;
			}else{
				continue;
			}
		}

		bool isRight = true;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == maxNum || maxNum >= nums[i] * 2)
			{
				continue;

			}else{
				isRight = false;
				break;;
			}
		}
		return (isRight == true ? maxNumIndex : -1);
	}

	int dominantIndex_vector(vector<int>& nums) {
		vector<int> copy(nums);
		auto maxPos = max_element(copy.begin(), copy.end()); // 寻找最大值位置
		if (maxPos == copy.end()) return true;
		int maxVal = *maxPos;  // 获取最大值
		int maxIndex = maxPos - copy.begin();  // 获取最大值索引
		copy.erase(maxPos); // 移除最大值
		return all_of(copy.begin(), copy.end(),[&maxVal](int v){return v*2 <= maxVal;}) ? maxIndex : -1;
	}
};