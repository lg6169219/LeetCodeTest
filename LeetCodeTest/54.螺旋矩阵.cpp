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
		if (row == 0)
			return {};

		int col = matrix[0].size();

		int startIndexX = 0; // ++
		int endIndexX = row - 1;

		int startIndexY = 0; // ++
		int endIndexY = col - 1;

		vector<int> vec;
		for (; startIndexX <= endIndexX && startIndexY<=endIndexY; startIndexX++,endIndexX--,startIndexY++,endIndexY--) // 控制总的回型遍历次数
		{
			// 前两个for考虑的是单行或者单列的时候，加上后两个for就是考虑有四条边的时候

			vector<int> vecData = matrix[startIndexX];
			// -----
			for (int i = startIndexY; i <= endIndexY; ++i){
				vec.push_back(vecData[i]);
			}

			//------
			//     -
			//     -
			//     -
			for (int i = startIndexX + 1; i <= endIndexX; ++i){
				vec.push_back(matrix[i][endIndexY]);
			}

			// 去重
			if (startIndexX < endIndexX && startIndexY < endIndexY)
			{
				//------
				//     -
				//     -
				//     -
				// -----
				vecData = matrix[endIndexX];
				for (int i = endIndexY - 1; i > startIndexY; --i)
				{
					vec.push_back(vecData[i]);
				}

				//------
				//-    -
				//-    -
				//-    -
				//------
				for (int i = endIndexX; i > startIndexX; --i){
					vec.push_back(matrix[i][startIndexY]);
				}
			}
		}
		return vec;
	}
};