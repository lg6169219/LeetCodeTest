/**
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。


方法一：双指针法，动态维护区间 原理不太理解

求符合条件的最小的连续子区间，可以采用双指针法，动态维护一个符合条件的区间。

设置两个指针，left和right，分别标记当前维护的区间的左端和右端
如果当前区间和小于s,则右移right，直至大于等于s
如果当前区间和大于s，则右移left，直至小于等于s (这个过程需要记录最小的区间长度)
直至right遍历至数组结束，返回过程中记录的最小区间长度即可
该算法由于至多遍历两边数组，故时间复杂度是 O(n)O(n)


方法二：前缀和，二分查找

该方法思路主要是求子数组的和问题，通常都可以采用前缀和进行简化，将数组的和转化为前缀和数组中两个值的差。
该题中，由于数字都是正整数，因此前缀和是单调递增的，故可以每次确定一个 sum[i]sum[i]的位置，
然后利用二分查找的方法找左侧 sum[i]-ssum[i]−s 的位置。 O(n log n) 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int left = 0, right = 0; //双指针,维护一个大于等于s的区间
		int ans = INT_MAX, sum = 0;
		for (right=0; right < nums.size();++right)
		{
			sum+=nums[right];
			while (sum >= s) //如果当前的sum大于s,右移左指针，直至该条件不成立 
			{
				ans=min(ans, right - left +1); //刷新长度
				sum-=nums[left++]; //左指针右移,刷新sum
			}
		}
		return ans==INT_MAX?0:ans;
	}

	int minSubArrayLen_2(int s, vector<int>& nums) {
		vector<int> sum(nums.size() + 1);
		sum[0]=0;  //注意将sum[0]初始化为0
		if(nums.size()==0) 
			return 0;

		for(int i=1;i<sum.size();i++)
		{
			sum[i]=sum[i-1]+nums[i-1];
		}
		int ans=INT_MAX;
		for(int i=0;i<sum.size();i++){
			//lower_bound返回容器中大于等于val的第一个元素位置,具体的原理是二分查找，因此它只能用于非降序序列。
			if (sum[i] + s > sum[sum.size()] - 1)
				break;
			
			int pos = lower_bound(sum.begin(), sum.end(), sum[i] + s) - sum.begin();
			ans = min(ans, pos - i); //由于多了一个sum[0],因此计算长度时实际上是pos-i即可
		}
		return ans==INT_MAX?0:ans;
	}
};