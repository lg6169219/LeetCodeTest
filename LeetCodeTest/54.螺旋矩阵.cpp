/**
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

思路
	回字形读取，每次的起点在对角线上
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
		int num = ceil(val / 2); // 循环的次数

		for (int i = 0; i < num; ++i)
		{
		}
	}
};