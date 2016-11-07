#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 ��һ��map��¼����һ���ڵ㼰���������õ���ֵ
 second��ʾ�����ýڵ㣬first��ʾ�����߲������ܻ�õ����ֵ
 ������һ��ʱfirstĬ��Ϊ���˸��ӽڵ㣬���ǲ��������ڵ�
 l1��l2��r1��r2��4������Ҳ���Բ�Ҫ��Ϊʹ���濴�������
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
