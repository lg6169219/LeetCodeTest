/**
	给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
	注意遍历的顺序，像穿针一样

	解决许多复杂问题的常见策略是首先解决该问题的简化问题，然后考虑从简化问题到原始问题需要做哪些修改，方法一就是这种思路。
	首先考虑按照逐条对角线打印元素，而不考虑翻转的情况。
	1	2	3	4		0，0	0,1		0,2		0,3
	5	6	7	8		1,0		1,1		1,2		1,3
	9	10	11	12		2,0		2,1		2,2		2,3

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		/**总的遍历次数row + col - 1*/
		// !!!! 对空值的判断不能忘记
		int row = matrix.size();
		if (row <= 0)
			return {};

		int col = matrix[0].size();
		int total = row + col - 1;
		vector<int> vec;

		for(int i = 0; i < total; ++i){
			
			//偶数趟遍历x++ y--
			if (i % 2 != 0)
			{
				int y = i < col ? i : col - 1;
				int x = i - y;
				for (; x <= row - 1 && y >= 0; x++,y--)
				{
					vec.push_back(matrix[x][y]);
				}
			}else{
				// x-- y++
				int x = i < row ? i : row - 1;
				int y = i - x;
				for (; x >= 0 && y <= col - 1 ; x--,y++)
				{
					vec.push_back(matrix[x][y]);
				}
			}
			// row-1~total-1次遍历
		}
		return vec;
	}
};