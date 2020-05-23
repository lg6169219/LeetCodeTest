/**
	����һ������ M x N ��Ԫ�صľ���M �У�N �У������ԶԽ��߱�����˳�򷵻���������е�����Ԫ�أ��Խ��߱�������ͼ��ʾ��
	ע�������˳������һ��

	�����ิ������ĳ������������Ƚ��������ļ����⣬Ȼ���ǴӼ����⵽ԭʼ������Ҫ����Щ�޸ģ�����һ��������˼·��
	���ȿ��ǰ��������Խ��ߴ�ӡԪ�أ��������Ƿ�ת�������
	1	2	3	4		0��0	0,1		0,2		0,3
	5	6	7	8		1,0		1,1		1,2		1,3
	9	10	11	12		2,0		2,1		2,2		2,3

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		/**�ܵı�������row + col - 1*/
		// !!!! �Կ�ֵ���жϲ�������
		int row = matrix.size();
		if (row <= 0)
			return {};

		int col = matrix[0].size();
		int total = row + col - 1;
		vector<int> vec;

		for(int i = 0; i < total; ++i){
			
			//ż���˱���x++ y--
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
			// row-1~total-1�α���
		}
		return vec;
	}
};