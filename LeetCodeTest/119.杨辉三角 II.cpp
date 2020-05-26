/**
����һ���Ǹ����� k������ k �� 33������������ǵĵ� k �С�
����: 3
���: [1,3,3,1]

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
������Ż�����㷨�� O(k) �ռ临�Ӷ���
	��ʼ��һ������O(k+1)������
	n+1�е�������ʵ����n�����ݵ����ģ�����ֱ�Ӹ���
	�Ӻ���ǰ��������ǰλ�õ�ֵ���ڵ�ǰλ�����ڵ�ֵ+(��ǰλ��-1)��ֵ
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<vector<int>> vec;
		// �ȴ����
		for (int i = 0; i < rowIndex; ++i)
		{
			vector<int> v(i + 1, 1);
			vec.push_back(v); // push_back���Զ�̬����
		}

		if (rowIndex <= 1)
		{
			return vec[rowIndex];
		}

		for (int i = 2; i < rowIndex + 1; ++i)
		{
			int size = vec[i].size();
			for (int j = 1; j < size - 1; ++j)
			{
				vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
			}
		}
		return vec[rowIndex];
	}

	vector<int> getRow_1(int rowIndex) {
		int len = rowIndex + 1;
		vector<int> v(len, 1);
		if (len <= 2)
			return v;

		for (int i = 2; i < len; ++i)
		{
			for (int j = i - 1; j > 0; --j)
			{
				v[j] = v[j] + v[j-1];
			}
		}

		return v;
	}
};

1
1 1
1 2 1
1 3 3 1

k = 3
i = 2 len = 4 j = 1  v[j] = 2