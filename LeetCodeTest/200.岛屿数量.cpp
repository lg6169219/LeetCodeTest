#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution{
private:
	/**
		深度优先搜索
		时间复杂度：O(MN)O(MN)，其中 MM 和 NN 分别为行数和列数。
		空间复杂度：O(MN)O(MN)，在最坏情况下，整个网格均为陆地，深度优先搜索的深度达到 M NMN。
	*/
	void dfs(vector<vector<char>>& grid, int r, int c){
		int nr = grid.size();
		int nc = grid[0].size();
		/**
			深度遍历的位置设置为0
			对上下左右进行深度遍历
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
	/**pair include <utility> 或者include <map>*/
	/************************************************************************/
	/* 
	广度优先搜索
	为了求出岛屿的数量，我们可以扫描整个二维网格。
	如果一个位置为 11，则将其加入队列，开始进行广度优先搜索。
	在广度优先搜索的过程中，每个搜索到的 11 都会被重新标记为 00。直到队列为空，搜索结束。
	最终岛屿的数量就是我们进行广度优先搜索的次数。
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
	并查集
	概念介绍 门派、掌门 https://blog.csdn.net/niushuai666/article/details/6662911
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

	/**找一个union的根节点 也就是一个门派的掌门*/
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
	/**路径压缩rank*/
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