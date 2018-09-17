/**
 * 分别找到左右子树的最长合法path，然后再判断root->val和左右子树的val是否连续，连续可+1
 * 还需一个“全局”变量，保存全局最大path，这个在函数中可以用int& 来完成，就使得所有函数都去改那一块内存，就起到全局变量的作用
 * 但是到达这个点的longestPath不能用函数中的int& 参数来表示，原因与前类似，不能每个函数都去改这块内存
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
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        findLongestPath(root, longest);
        return longest;
    }
    int findLongestPath(TreeNode* root, int& longest) {
        if (!root) {
            return 0;
        }
        int left = findLongestPath(root->left, longest);
        int right = findLongestPath(root->right, longest);
        int path = 1;
        if (root->left && root->val == root->left->val - 1) {
            path = max(path, left + 1);
        }
        if (root->right && root->val == root->right->val - 1) {
            path = max(path, right + 1);
        }
        longest = max(longest, path);
        return path;
    }
};
