/**
����һ������ m x n ��Ԫ�صľ���m ��, n �У����밴��˳ʱ������˳�򣬷��ؾ����е�����Ԫ�ء�

˼·
	�����ζ�ȡ��ÿ�ε�����ڶԽ�����
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		int val = min(row, col);
		int num = ceil(val / 2); // ѭ���Ĵ���

		for (int i = 0; i < num; ++i)
		{
		}
	}
};