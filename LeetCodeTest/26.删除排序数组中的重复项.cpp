/**
����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�



ʾ�� 1:

�������� nums = [1,1,2], 

����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2�� 

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
ʾ�� 2:

���� nums = [0,0,1,1,1,2,2,3,3,4],

����Ӧ�÷����µĳ��� 5, ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��

�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

˼·
�ÿ���ָ��
һ��currentָ�루��ǰ�Ա�ָ�룩����������
һ��findָ�룬�ҵ���һ����current����ȵ�ֵ��λ�ã��ŵ�currentλ����
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