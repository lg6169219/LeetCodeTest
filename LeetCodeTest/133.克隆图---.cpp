/**主要思想是通过递归，创建和更新新的图节点。*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	Node* used[101];           //创建一个节点（指针）数组记录每个拷贝过的节点
	Node* cloneGraph(Node* node) {
		if(!node)return node;   //如果是空指针，则返回空
		if(used[node->val])return used[node->val];  //该节点已经拷贝，直接返回该节点的指针即可
		Node* p=new Node(node->val);    //创建拷贝节点
		used[node->val]=p;             //递归会遍历每一个原有节点，然后将拷贝后的指针放入used
		vector<Node*> tp = node->neighbors;
		for(int i=0;i<tp.size();i++) //将该节点的邻接节点放入拷贝节点邻接数组
			p->neighbors.push_back(cloneGraph(tp[i]));//递归实现每一个节点的更新
		return p;           //返回拷贝后的节点
	}
};