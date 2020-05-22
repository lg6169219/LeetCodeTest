/**
	输入: 
	image = [[1,1,1],[1,1,0],[1,0,1]]
	sr = 1, sc = 1, newColor = 2
	输出: [[2,2,2],[2,2,0],[2,0,1]]
	解析: 
	在图像的正中间，(坐标(sr,sc)=(1,1)),
	在路径上所有符合条件的像素点的颜色都被更改成2。
	注意，右下角的像素没有更改为2，
	因为它不是在上下左右四个方向上与初始点相连的像素点。

	注意:
	image 和 image[0] 的长度在范围 [1, 50] 内。
	给出的初始点将满足 0 <= sr < image.length 和 0 <= sc < image[0].length。
	image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535]内。

	思路
	以输入的点(sr,sc)做深度遍历，将=1的点全部改为2
*/

#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
	void dfs(vector<vector<int>>& image, int sr, int sc, int newColor){
		int row = image.size();
		int col = image[0].size();

		int val = image[sr][sc];
		image[sr][sc] = newColor;

		if (sr - 1 >= 0 && image[sr-1][sc] == val)
			dfs(image, sr-1, sc, newColor);
		if (sr + 1 < row && image[sr+1][sc] == val)
			dfs(image, sr+1, sc, newColor);
		if (sc - 1 >= 0 && image[sr][sc-1] == val)
			dfs(image, sr, sc-1, newColor);
		if (sc + 1 < col && image[sr][sc+1] == val)
			dfs(image, sr, sc+1, newColor);
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if(image[sr][sc] == newColor){
			return image;
		}
		dfs(image, sr, sc, newColor);

		return image;
	}

	/**用while循环和队列 ??? 超时了*/
	vector<vector<int>> floodFill_queue(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if(image[sr][sc] == newColor){
			return image;
		}

		queue<pair<int, int>> st;
		int row = image.size();
		int col = image[0].size();

		st.push(make_pair(sr, sc));

		while (!st.empty())
		{
			pair<int, int> data = st.front();
			st.pop();
			int val = image[data.first][data.second];
			image[data.first][data.second] = newColor;

			int r = data.first;
			int c = data.second;


			if (r - 1 >= 0 && image[r-1][c] == val)
				st.push(make_pair(r-1, c));
			if (r + 1 < row && image[r+1][c] == val)
				st.push(make_pair(r+1, c));
			if (c - 1 >= 0 && image[r][c-1] == val)
				st.push(make_pair(r, c-1));
			if (c + 1 < col && image[r][c+1] == val)
				st.push(make_pair(r, c+1));
		}

		return image;
	}
};