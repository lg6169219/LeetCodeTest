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
		if (row == 0)
			return {};

		int col = matrix[0].size();

		int startIndexX = 0; // ++
		int endIndexX = row - 1;

		int startIndexY = 0; // ++
		int endIndexY = col - 1;

		vector<int> vec;
		for (; startIndexX <= endIndexX && startIndexY<=endIndexY; startIndexX++,endIndexX--,startIndexY++,endIndexY--) // �����ܵĻ��ͱ�������
		{
			// ǰ����for���ǵ��ǵ��л��ߵ��е�ʱ�򣬼��Ϻ�����for���ǿ����������ߵ�ʱ��

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

			// ȥ��
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