/**
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
输入: 3
输出: [1,3,3,1]

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
你可以优化你的算法到 O(k) 空间复杂度吗？
	初始化一个长度O(k+1)的数组
	n+1行的数据其实是由n行数据得来的，所以直接复用
	从后往前遍历，当前位置的值等于当前位置现在的值+(当前位置-1)的值
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
		// 先处理边
		for (int i = 0; i < rowIndex; ++i)
		{
			vector<int> v(i + 1, 1);
			vec.push_back(v); // push_back可以动态扩容
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