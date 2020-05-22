/**
	����: 
	image = [[1,1,1],[1,1,0],[1,0,1]]
	sr = 1, sc = 1, newColor = 2
	���: [[2,2,2],[2,2,0],[2,0,1]]
	����: 
	��ͼ������м䣬(����(sr,sc)=(1,1)),
	��·�������з������������ص����ɫ�������ĳ�2��
	ע�⣬���½ǵ�����û�и���Ϊ2��
	��Ϊ�����������������ĸ����������ʼ�����������ص㡣

	ע��:
	image �� image[0] �ĳ����ڷ�Χ [1, 50] �ڡ�
	�����ĳ�ʼ�㽫���� 0 <= sr < image.length �� 0 <= sc < image[0].length��
	image[i][j] �� newColor ��ʾ����ɫֵ�ڷ�Χ [0, 65535]�ڡ�

	˼·
	������ĵ�(sr,sc)����ȱ�������=1�ĵ�ȫ����Ϊ2
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

	/**��whileѭ���Ͷ��� ??? ��ʱ��*/
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