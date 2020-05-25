/**
485. �������1�ĸ���
����һ�����������飬 ���������������1�ĸ�����

ʾ�� 1:

����: [1,1,0,1,1,
1]
���: 3
����: ��ͷ����λ��������λ��������1�������������1�ĸ����� 3.
ע�⣺

���������ֻ���� 0 ��1��
��������ĳ��������������Ҳ����� 10,000��
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		// ����ָ��
		

		int i = 0;
		int j = nums.size();
		if (j <= 0)
		{
			return 0;
		}
		int currNum = 0;
		int maxNum = 0;

		for (int i = 0; i < j; ++i)
		{
			if(nums[i] == 1){
				++currNum;
				maxNum = max(maxNum, currNum);
			}else{
				maxNum = max(maxNum, currNum);
				currNum = 0;
			}
		}
		return maxNum;
	}
};