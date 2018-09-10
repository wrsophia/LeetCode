/**
 * 有两种情况，一种是rob root，另一种是不rob root
 * rob root的时候就需要保证root->left和root->right不被rob
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
    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int notRobRoot = rob(root->left) + rob(root->right);
        int robRoot = root->val;
        if (root->left) {
            robRoot += rob(root->left->right) + rob(root->left->left);
        }
        if (root->right) {
            robRoot += rob(root->right->left) + rob(root->right->right);
        }
        return max(robRoot, notRobRoot);
    }
};
