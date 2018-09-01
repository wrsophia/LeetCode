/**
 * bst tree 的特点是，任何一个节点，它的左子树都小于它，右子树都大于它
 * 于是在排好序的数组中任取一个数，它左边的就是它的左子树，右边的就是它的右子树
 * 那么要求 height-balanced 就可以每次取数组的中点作为 root，这样左右子树的高度就能基本相同
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size() - 1);
    }

    TreeNode* bst(vector<int>& nums, int l, int r) {
        if (r < l) {
            return NULL;
        }
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = bst(nums, l, mid - 1);
        root->right = bst(nums, mid + 1, r);
        return root;
    }
};
