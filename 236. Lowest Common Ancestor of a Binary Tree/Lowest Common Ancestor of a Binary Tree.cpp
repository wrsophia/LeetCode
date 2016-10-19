#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		deque<TreeNode*> que1, que2;
		bool result1 = findpath(root, p, que1);
		bool result2 = findpath(root, q, que2);
		TreeNode* ancestor = NULL;
		if (result1 && result2)
		{
			while (!que1.empty() && !que2.empty() && que1.front() == que2.front())
			{
					ancestor = que1.front();
					que1.pop_front(), que2.pop_front();
			}
		}
		return ancestor;
	}
	

	bool findpath(TreeNode* root, TreeNode* node, deque<TreeNode*>& path) {
		if (root == node) {
			path.push_back(root);
			return true;
		}
		bool result = false;
		path.push_back(root);
		if (!result && root->left) {
			result = findpath(root->left, node, path);
		}
		if (!result && root->right) {
			result = findpath(root->right, node, path);
		}
		if (!result) path.pop_back();
		return result;
	}
};

int main()
{
	TreeNode* pRoot = new TreeNode(1);
	TreeNode* node1 = pRoot->left = new TreeNode(3);
	TreeNode* node2 = pRoot->right = new TreeNode(5);
	Solution sol;
	cout << sol.lowestCommonAncestor(pRoot, node1, node2)->val << endl;

	system("pause");
	return EXIT_SUCCESS;
}
