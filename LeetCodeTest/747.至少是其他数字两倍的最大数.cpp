#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

/**
����: nums = [3, 6, 1, 0]
���: 1
����: 6����������, ���������е���������,
6��������������Ԫ�ص�������6��������1, �������Ƿ���1.
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
		auto maxPos = max_element(copy.begin(), copy.end()); // Ѱ�����ֵλ��
		if (maxPos == copy.end()) return true;
		int maxVal = *maxPos;  // ��ȡ���ֵ
		int maxIndex = maxPos - copy.begin();  // ��ȡ���ֵ����
		copy.erase(maxPos); // �Ƴ����ֵ
		return all_of(copy.begin(), copy.end(),[&maxVal](int v){return v*2 <= maxVal;}) ? maxIndex : -1;
	}
};