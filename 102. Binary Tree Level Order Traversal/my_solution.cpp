/**
 * bfs
 * 可以用NULL来区别每一层，拿到一个节点，把它的孩子入队，碰到NULL节点再放入一个NULL与下一层隔断
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        queue<TreeNode*> treeNodes;
        treeNodes.push(root);
        treeNodes.push(NULL);

        vector<int> tmp;
        while (!treeNodes.empty()) {
            TreeNode* curr = treeNodes.front();
            treeNodes.pop();
            if (!curr) {
                res.push_back(tmp);
                if (treeNodes.empty()) {
                    return res;
                }
                tmp = vector<int> ();    // 这样可以相当于让指针指向一个新数组
                treeNodes.push(NULL);
            } else {
                tmp.push_back(curr->val);
                if (curr->left) {
                    treeNodes.push(curr->left);
                }
                if (curr->right) {
                    treeNodes.push(curr->right);
                }
            }

        }
    }
};
