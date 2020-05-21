/**���������������*/
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	/**
		����ջ�ı����ⷨ
		vector<int> reslist ��Ž��
		stack<TreeNode*> stNode �ڵ�ջ
		TreeNode* currNode ��ǰ�ڵ�

		ջS;������
		p= root;
		while(p || S����){
			while(p){
				����p�ڵ㣻
				p����������S;
				p = p��������;
			}
			p = Sջ������;
		}

		ջS;������
		p= root;
		while(p || S����){
			while(p){
				p��S;
				p = p��������;
			}
			p = S.top ��ջ;
			����p;
			p = p��������;
		}
	*/
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> reslist;
		stack<TreeNode*> stNode;
		TreeNode* currNode = root;

		while (currNode != NULL || !stNode.empty())
		{
			while (currNode)
			{
				stNode.push(currNode);
				currNode = currNode->left;
			}
			currNode = stNode.top();
			stNode.pop();
			reslist.push_back(currNode->val);
			currNode = currNode->right;
		} 
		return reslist;
	}

	/**�ݹ�ⷨ*/
	void recursion(TreeNode* root, vector<int>& list){
		if(root->left)
			recursion(root->left, list);
		list.push_back(root->val);
		if(root->right)
			recursion(root->right, list);
	}

	vector<int> inorderTraversal(TreeNode* root){
		vector<int> list;
		recursion(root, list);
		return list;
	}
};