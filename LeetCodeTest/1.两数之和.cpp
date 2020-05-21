#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 示例:

 给定 nums = [2, 7, 11, 15], target = 9

 因为 nums[0] + nums[1] = 2 + 7 = 9
 所以返回 [0, 1]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/two-sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution01 {
public:
	// 暴力解法遍历  复杂度O(N^2)
	vector<int> twoSum01(vector<int>& nums, int target) {
		vector<int> it;
		for(int i = 0; i < nums.size(); ++i){
			for(int j = i + 1; j < nums.size(); ++j){
				if (nums[i] + nums[j] == target){
					it.push_back(i);
					it.push_back(j);
					return it;
				}
			}
		}
		return it;
	}
	//进阶解法 使用哈希表unordered_map
	vector<int> twoSum02(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		vector<int> it;
		for(int i = 0; i < nums.size(); ++i){
			if (map.find(target - nums[i]) != map.end())
			{
				it.push_back(map[target-nums[i]]);
				it.push_back(i);
				return it;
			}
			map[nums[i]] = i;
		}
		return it;
	}
};