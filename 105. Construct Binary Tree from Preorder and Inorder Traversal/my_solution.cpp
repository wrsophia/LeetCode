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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preLength = preorder.size();
        int inLength = inorder.size();

        if (preLength == 0 || preLength != inLength) {
            return NULL;
        }
        return buildTree(preorder, 0, preLength - 1, inorder, 0, inLength - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, int preL, int preR, vector<int>& inorder, int inL, int inR) {
        if (preR == preL) {
            return new TreeNode(preorder[preL]);
        }

        TreeNode* root = new TreeNode(preorder[preL]);
        int rootIdx = inL;      // root在中序遍历中的位置
        while (rootIdx <= inR) {
            if (inorder[rootIdx] == preorder[preL]) {
                break;
            }
            ++rootIdx;
        }
        if (rootIdx > inL) {
            root->left = buildTree(preorder, preL + 1, preL + rootIdx - inL, inorder, inL, rootIdx - 1);
        }
        if (rootIdx < inR) {
            root->right = buildTree(preorder, preL + rootIdx - inL + 1, preR, inorder, rootIdx + 1, inR);
        }
        return root;
    }

};
