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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        pathSum(res, path, root, sum);
        return res;
    }

    void pathSum(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right && sum == 0) {
            res.push_back(path);      // push_back() 会把path复制一份，所以公用一个path数组是够用的
        } else {
            pathSum(res, path, root->left, sum);
            pathSum(res, path, root->right, sum);
        }
        path.pop_back();
        return;
    }
};
