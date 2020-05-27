/**
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

ʾ��:

����: [0,1,0,3,12]
���: [1,3,12,0,0]
˵��:

������ԭ�����ϲ��������ܿ�����������顣
�������ٲ���������

˼·
��˫ָ��ѷ�����Ų��ǰ�棬�ٰѺ��������ֵΪ0
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

