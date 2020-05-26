/**
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	// 1 循环k次 每次整体移动一位 将末尾放置到首位
	// 时间复杂度很大 O(n^2)
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0)
			return;

		if (k == 0 || (k % len) == 0){
			return;
		};

		int trueK = k % len;
		int temp,previous;
		for (int i = 0; i < trueK; ++i)
		{
			previous = nums[len - 1];
			for (int j = 0; j < len; ++j)
			{
				temp = nums[j];
				nums[j] = previous;
				previous = temp;
			}
		}
	}

	// 方法 2：使用额外的数组 但是需要额外的空间
	void rotate_1(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0)
			return;

		if (k == 0 || (k % len) == 0){
			return;
		};
		stack<int> st;
		int trueK = k % len;

		for (int i = len - 1; i >= 0; ++i)
		{
			if (i >= len - trueK)
			{
				st.push(nums[i]);
			}else{
				nums[i+trueK] = nums[i];
			}
		}

		int size = st.size();
		for (int i = 0; i < size; ++i)
		{
			nums[i] = st.top();
			st.pop();
		}
	}

	// 方法4 使用翻转
	/**
	原始数组                  : 1 2 3 4 5 6 7
	反转所有数字后             : 7 6 5 4 3 2 1
	反转前 k 个数字后          : 5 6 7 4 3 2 1
	反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果

	时间复杂度：O(n)。 n个元素被反转了总共 3 次。
	空间复杂度：O(1)。 没有使用额外的空间。

	reverse函数用于反转在[first,last)范围内的顺序（包括first指向的元素，不包括last指向的元素）
	*/
	void rotate_1(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0)
			return;

		if (k == 0 || (k % len) == 0){
			return;
		};
		int trueK = k % len;

		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin()+trueK);
		reverse(nums.begin()+trueK, nums.end());
	}
};