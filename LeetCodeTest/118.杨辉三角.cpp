/**
输入: 5
输出:
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]

思路
先构造一个全1的二维数组
对非边元素进行处理
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vec;
		if (numRows <= 0)
		{
			return vec;
		}

		for (int i = 0; i < numRows; ++i)
		{
			int nums = i + 1;
			vector<int> line(nums,1);
			vec.push_back(line);
		}
		if(numRows <= 2)
			return vec;

		for (int i = 0; i < numRows; ++i)
		{
			int nums = i + 1;
			for (int j = 1; j < nums - 1; ++j)
			{
				vec[i][j] = (vec[i-1][j-1] == NULL ? 0 : vec[i-1][j-1]) + (vec[i-1][j] == NULL ? 0 : vec[i-1][j]);
			}
		}  

		return vec;
	}
};