#include <iostream>
#include <cstdlib>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int count;
	int kthSmallest(TreeNode* root, int k) {
		int result = 0;
		if (root->left != NULL && count < k)
			result = kthSmallest(root->left, k);
		count++;    //记录当前节点的计数
		if (count == k)
			result = root->val;
		if (root->right != NULL && count < k)
			result = kthSmallest(root->right, k);
		return result;
	}
	Solution() : count(0) { };
};