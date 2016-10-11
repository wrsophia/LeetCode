#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;

//��һ��parent���������жϵ�ǰҶ�ӽڵ�node�Ƿ�Ϊĳ�ڵ������

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL)
			return 0;
		return sumOfLeftLeaves(root, NULL);
	}
	int sumOfLeftLeaves(TreeNode* node, TreeNode* parent) {
		int sum = 0;
		if (node->left)
			sum += sumOfLeftLeaves(node->left, node);
		if (node->right)
			sum += sumOfLeftLeaves(node->right, node);
		if (node->left == NULL && node->right == NULL && parent != NULL && parent->left == node)
			sum += node->val;
		return sum;
	}
};