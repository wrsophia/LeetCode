/**
 * 思路就是，检验左子树和右子树是否都是平衡二叉树，并且他们的高度差不超过1
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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isBalanced(root->left) && isBalanced(root->right)
            && height(root->left) <= height(root->right) + 1 && height(root->right) <= height(root->left) + 1;
    }

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
};
