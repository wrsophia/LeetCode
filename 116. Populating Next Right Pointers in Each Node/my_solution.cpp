/**
 * 这道题tricky的地方在于，connect完左子树和右子树之后需要递归的把每层中间的缝隙连起来
 */


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }

        connect(root->left);
        connect(root->right);

        TreeLinkNode *left = root->left, *right = root->right;
        while (left) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
        return;
    }
};
