/**
 * 这个题的坑在于，如果某个点只有左子树或只有右子树，那么它的height不是1，而是它的子树高度+1
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if ((l == 0 && r == 0) || (l != 0 && r != 0)) {
            return min(l, r) + 1;
        } else if (l == 0) {
            return r + 1;
        } else {
            return l + 1;
        }
    }
};
