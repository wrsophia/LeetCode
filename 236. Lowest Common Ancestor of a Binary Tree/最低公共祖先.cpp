#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
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
		stack<TreeNode*> stack1, stack2;
		bool result1 = FindPath(root, p, stack1);
		bool result2 = FindPath(root, q, stack2);
		TreeNode* ancestor = NULL;
		if (result1 && result2)
		{
			while (!stack1.empty() && !stack2.empty())
			{
				if (stack1.top() == stack2.top())
				{
					ancestor = stack1.top();
					stack1.pop(), stack2.pop();
				}
				else
					break;
			}
		}
		return ancestor;
	}
	bool FindPath(TreeNode* root, TreeNode* node, stack<TreeNode*>& path)
	{
		if (root == NULL)
			return false;
		if (root == node)
		{
			path.push(root);
			return true;
		}
		bool result = false;
		if (!result)
			result = FindPath(root->left, node, path);
		if (!result)
			result = FindPath(root->right, node, path);
		if (result)
			path.push(root);
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
