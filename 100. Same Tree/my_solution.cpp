/**
 * 思路就是检查当前节点，再递归检查左右子树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool sameNode = (p && q && p->val == q->val) || (!p && !q);
        if (sameNode) {
            if (p && q) {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            } else {
                return true;
            }
        } else {
            return false;
        }

    }
};
