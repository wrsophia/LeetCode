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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inLen = inorder.size();
        int postLen = postorder.size();

        if (inLen == 0 || inLen != postLen) {
            return NULL;
        }
        return buildTree(inorder, 0, inLen - 1, postorder, 0, postLen - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, int inL, int inR, vector<int>& postorder, int postL, int postR) {
        if (inR == inL) {
            return new TreeNode(inorder[inL]);
        }

        TreeNode* root = new TreeNode(postorder[postR]);
        int rootIdx = inL;      // root在中序遍历中的位置
        while (rootIdx <= inR) {
            if (inorder[rootIdx] == postorder[postR]) {
                break;
            }
            ++rootIdx;
        }
        if (rootIdx > inL) {
            root->left = buildTree(inorder, inL, rootIdx - 1, postorder, postL, postL + rootIdx - inL - 1);
        }
        if (rootIdx < inR) {
            root->right = buildTree(inorder, rootIdx + 1, inR, postorder, postL + rootIdx - inL, postR - 1);
        }
        return root;
    }
};
