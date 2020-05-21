#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <queue>
using namespace std;

int n;
vector< list<int> > graph;
bool visited[100] = {0};

void dfs(int v)
{
	list<int>::iterator it;
	visited[v] = true;
	printf("%5d", v);
	for (it = graph[v].begin(); it != graph[v].end(); ++it)
		if (!visited[*it])
			dfs(*it);
}

/*
int search(int t)
{
	if(满足输出条件)
	{
		输出解;
	}
	else
	{
		for(int i=1;i<=尝试方法数;i++)
			if(满足进一步搜索条件)
			{
				为进一步搜索所需要的状态打上标记;
				search(t+1);
				恢复到打标记前的状态;//也就是说的{回溯一步}
			}
	}
}
*/

void bfs(int v)
{
	list<int>::iterator it;
	printf("%5d", v);
	visited[v] = true;
	queue<int> t;
	t.push(v);
	while (!t.empty())
	{
		v = t.front();
		t.pop();
		for (it = graph[v].begin(); it != graph[v].end(); ++it)
			if (!visited[*it])
			{
				printf("%5d", *it);
				t.push(*it);
				visited[*it] = true;
			}
	}
	cout << endl;
}

/************************************************************************/
/* 按照链表表示输入以下数据：
8
0 1 2 8
1 0 3 4 8
2 0 5 6 8
3 1 7 8
4 1 7 8
5 2 7 8
6 2 7 8
7 3 4 5 6 8

最后一个8用来标识这个节点输入结束。可以得到深搜和广搜的结果。*/
/************************************************************************/
int main()
{
	//freopen("in.txt", "r", stdin);
	cout << "input the vertex num:"<< endl;
	cin >> n;
	vector< list<int> >::iterator it;
	for (int i = 0; i < n; ++i)
	{
		list<int> il;
		int t;
		while (cin >> t && t != n)
			il.push_back(t);
		graph.push_back(il);
	}
	cout << "result for bfs:" << endl;
	bfs(0);
	memset(visited, 0, sizeof(visited));                   //重新初始化标志数组
	cout << "result for dfs:" << endl;
	dfs(0);

	system("pause");
	return 0;
}