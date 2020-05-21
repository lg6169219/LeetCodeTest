/**二叉树的中序遍历*/
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
		基于栈的遍历解法
		vector<int> reslist 存放结果
		stack<TreeNode*> stNode 节点栈
		TreeNode* currNode 当前节点

		栈S;（先序）
		p= root;
		while(p || S不空){
			while(p){
				访问p节点；
				p的右子树入S;
				p = p的左子树;
			}
			p = S栈顶弹出;
		}

		栈S;（中序）
		p= root;
		while(p || S不空){
			while(p){
				p入S;
				p = p的左子树;
			}
			p = S.top 出栈;
			访问p;
			p = p的右子树;
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

	/**递归解法*/
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