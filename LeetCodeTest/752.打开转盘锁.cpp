#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/**
	该密码锁有4位，每位可加减 加减各算一种情况 可用函数表示，4×2 一共有8种情况（类似于bfs中8个方向的遍历），
	其中会有重复情况出现（出现回路），利用一个set存储遍历过的情况，遇到在deaddends里的情况则跳出当前循环即可。 
	可参考labudong大佬bfs框架

	广度搜索就用队列。
	用一个VISITED数组保存已经走过的位置。
	一个队列按层来保存
	在一层中取每个节点。
	如果该节点为deadends中的值就跳过本次循环。
	如果找到了目标就返回
	没找到就把该节点的下一层保存起来。，用visited避免重复。

	一层结束后++res
*/
class Solution{
public:
	string plusone(string str, int i){
		if (str[i] == '9')
		{
			str[i] = '0';
		}else{
			str[i] = str[i] + 1;
		}
		return str;
	}
	string downone(string str, int i){
		if (str[i] == '0')
		{
			str[i] = '9';
		}else{
			str[i] = str[i] - 1;
		}
		return str;
	}

	int openLock(vector<string>& deadends, string target){
		unordered_set<string> deadset(deadends.begin(), deadends.end());
		queue<string> q;
		q.push("0000");
		unordered_set<string> visited;
		visited.insert("0000");
		int step = 0;

		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				string str = q.front();
				q.pop();

				if (deadset.find(str) != deadset.end())
				{
					continue;
				}
				if (str == target)
				{
					return step;
				}
				/**尝试拨动数字*/
				for (int i = 0; i < 4; ++i)
				{
					string up = plusone(str, i);
					if (!visited.count(up))
					{
						q.push(up);
						visited.insert(up);
					}

					string down = downone(str, i);
					if (!visited.count(down))
					{
						q.push(down);
						visited.insert(down);
					}
				}
			}
			step++;
		}
		return -1;
	}
};