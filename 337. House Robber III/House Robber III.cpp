#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 用一个map记录抢完一个节点及其子树所得到的值
 second表示不抢该节点，first表示抢或者不抢所能获得的最大值
 返回上一层时first默认为抢了该子节点，于是不能抢父节点
 l1、l2、r1、r2这4个变量也可以不要，为使后面看起来简洁
 l->left, r->right, 1->first, 2->second
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	void dfs(TreeNode* node) {
		int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
		if (node->left) {
			dfs(node->left);
			l1 = hash[node->left].first;
			l2 = hash[node->left].second;
		}
		if (node->right) {
			dfs(node->right);
			r1 = hash[node->right].first;
			r2 = hash[node->right].second;
		}
		hash[node].first = node->val + l2 + r2;
		hash[node].second = l1 + r1;

		hash[node].first = max(hash[node].first, hash[node].second);
	}

	int rob(TreeNode* root) {
		if (root == NULL) return 0;
		hash.clear();
		dfs(root);
		return hash[root].first;
	}
private:
	unordered_map<TreeNode*, pair<int, int> > hash;
};
