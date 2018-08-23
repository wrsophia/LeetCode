/**
 * 非递归的三种遍历都是要用到栈的，前序和中序不需要用一个prev指针来保存上一个节点，后序需要
 * 每次都是不断的push左孩子，当没有左孩子的时候push右孩子，然后再不断的push左孩子
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            res.push_back(curr->val);
            s.pop();
            curr = curr->right;
        }
        return res;
    }
};
