/**��Ҫ˼����ͨ���ݹ飬�����͸����µ�ͼ�ڵ㡣*/
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
	Node* used[101];           //����һ���ڵ㣨ָ�룩�����¼ÿ���������Ľڵ�
	Node* cloneGraph(Node* node) {
		if(!node)return node;   //����ǿ�ָ�룬�򷵻ؿ�
		if(used[node->val])return used[node->val];  //�ýڵ��Ѿ�������ֱ�ӷ��ظýڵ��ָ�뼴��
		Node* p=new Node(node->val);    //���������ڵ�
		used[node->val]=p;             //�ݹ�����ÿһ��ԭ�нڵ㣬Ȼ�󽫿������ָ�����used
		vector<Node*> tp = node->neighbors;
		for(int i=0;i<tp.size();i++) //���ýڵ���ڽӽڵ���뿽���ڵ��ڽ�����
			p->neighbors.push_back(cloneGraph(tp[i]));//�ݹ�ʵ��ÿһ���ڵ�ĸ���
		return p;           //���ؿ�����Ľڵ�
	}
};