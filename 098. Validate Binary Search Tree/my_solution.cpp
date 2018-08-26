/**
 * 思路就是中序遍历，如果当前数字比先前数字小就return false
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if (prev && curr->val <= prev->val) {
                return false;
            }
            prev = curr;
            curr = curr->right;
        }
        return true;
    }
};
