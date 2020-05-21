#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution{
private:
	/**
		�����������
		ʱ�临�Ӷȣ�O(MN)O(MN)������ MM �� NN �ֱ�Ϊ������������
		�ռ临�Ӷȣ�O(MN)O(MN)���������£����������Ϊ½�أ����������������ȴﵽ M NMN��
	*/
	void dfs(vector<vector<char>>& grid, int r, int c){
		int nr = grid.size();
		int nc = grid[0].size();
		/**
			��ȱ�����λ������Ϊ0
			���������ҽ�����ȱ���
		*/
		grid[r][c] = '0';

		if(r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
		if(r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
		if(c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
		if(c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
	}
public:
	int numIslands_dfs(vector<vector<char>>& grid){
		int nr = grid.size();
		if(!nr) return 0;
		int nc = grid[0].size();

		int num_island = 0;
		for(int r = 0; r < nr; ++r){
			for(int c = 0; c < nc; ++c){
				if (grid[r][c] == '1')
				{
					++num_island;
					dfs(grid, r, c);
				}
			}
		}
		return num_island;
	}
	/**pair include <utility> ����include <map>*/
	/************************************************************************/
	/* 
	�����������
	Ϊ�������������������ǿ���ɨ��������ά����
	���һ��λ��Ϊ 11�����������У���ʼ���й������������
	�ڹ�����������Ĺ����У�ÿ���������� 11 ���ᱻ���±��Ϊ 00��ֱ������Ϊ�գ�����������
	���յ���������������ǽ��й�����������Ĵ�����
	*/
	/************************************************************************/
	int numIslands_bfs(vector<vector<char>>& grid){
		int nr = grid.size();
		if (!nr) return 0;
		int nc = grid[0].size();

		int num_islands = 0;
		for (int r = 0; r < nr; ++r) {
			for (int c = 0; c < nc; ++c) {
				if (grid[r][c] == '1') {
					++num_islands;
					grid[r][c] = '0';
					queue<pair<int, int>> neighbors;
					neighbors.push(make_pair(r, c));
					while (!neighbors.empty()) {
						auto rc = neighbors.front();
						neighbors.pop();
						int row = rc.first, col = rc.second;
						if (row - 1 >= 0 && grid[row-1][col] == '1') {
							neighbors.push(make_pair(row-1, col));
							grid[row-1][col] = '0';
						}
						if (row + 1 < nr && grid[row+1][col] == '1') {
							neighbors.push(make_pair(row+1, col));
							grid[row+1][col] = '0';
						}
						if (col - 1 >= 0 && grid[row][col-1] == '1') {
							neighbors.push(make_pair(row, col-1));
							grid[row][col-1] = '0';
						}
						if (col + 1 < nc && grid[row][col+1] == '1') {
							neighbors.push(make_pair(row, col+1));
							grid[row][col+1] = '0';
						}
					}
				}
			}
		}

		return num_islands;
	}
};


/**
	���鼯
	������� ���ɡ����� https://blog.csdn.net/niushuai666/article/details/6662911
*/
class UnionFind{

public:
	UnionFind(vector<vector<char>>& grid){
		count = 0;
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == '1')
				{
					parent.push_back(i * n + j);
					++count;
				}else{
					parent.push_back(-1);
				}
				rank.push_back(0);
			}
		}
	}

	/**��һ��union�ĸ��ڵ� Ҳ����һ�����ɵ�����*/
	int find(int i){
		if (parent[i] != i)
		{
			parent[i] = find(parent[i]);
		}
		return parent[i];
	}

	void unite(int x, int y){
		int rootx = find(x);
		int rooty = find(y);
		if (rootx != rooty)
		{
			if (rank[rootx] < rank[rooty])
			{
				swap(rootx, rooty); 
			}
			parent[rooty] = rootx;
			if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
			--count;
		}
	}

	int getCount() const{
		return count;
	}
private:
	vector<int> parent;
	/**·��ѹ��rank*/
	vector<int> rank;
	int count;
};

class SolutionUnion{
public:
	int numIslands(vector<vector<char>>& grid){
		int nr = grid.size();
		if (!nr) return 0;
		int nc = grid[0].size();

		UnionFind uf(grid);
		int num_islands = 0;
		for (int r = 0; r < nr; ++r)
		{
			for (int c = 0; c < nc; ++c){
				if (grid[r][c] == '1')
				{
					grid[r][c] = '0';
					if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
					if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
					if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
					if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
				}
			}
		}
		return uf.getCount();
	}
};