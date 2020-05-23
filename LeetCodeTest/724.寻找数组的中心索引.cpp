/**
����: 
nums = [1, 7, 3, 6, 5, 6]
���: 3
����: 
����3 (nums[3] = 6) �������֮��(1 + 7 + 3 = 11)�����Ҳ���֮��(5 + 6 = 11)��ȡ�
ͬʱ, 3 Ҳ�ǵ�һ������Ҫ�������������

˼·
���鳤��С��3 ����-1
��������Ԫ��֮��sum
�ӵ�0��Ԫ�ؿ�ʼ�������������ĺ� �Ҳ��=sum-���ĺ�-��Ԫ��

ע���ٽ�ֵ pos = 0 ����Ϊlength-1
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