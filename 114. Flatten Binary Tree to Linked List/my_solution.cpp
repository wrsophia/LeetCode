/**
 * 思路是非递归先序遍历的思路，每次向左走到头，用prev记录下该节点，表示下一个接上来的节点是接在此处
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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        stack<TreeNode*> s;

        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            if (!prev) {
                prev = curr;
            }

            s.pop();
            curr = curr->right;
            if (curr) {
                prev->left = curr;
                prev = NULL;

            }
        }

        curr = root;
        while (curr) {
            curr->right = curr->left;
            curr->left = NULL;
            curr = curr->right;
        }
    }
};
