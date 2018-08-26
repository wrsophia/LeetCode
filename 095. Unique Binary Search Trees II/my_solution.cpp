/**
 * 这个递归有点类似归并排序的递归
 * 参考96题的做法，以每个点作为根节点，它左侧的点生成它的左子树，右侧的点生成他的右子树
 * 然后在左、右子树的集合中挨个配对，生成以该节点为root的树，添加到vector里
 * 以此递归
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generate(1, n);
    }

    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generate(start, i - 1);
            vector<TreeNode*> right = generate(i + 1, end);

            for (int l = 0; l < left.size(); ++l) {
                for (int r = 0; r < right.size(); ++r) {
                    TreeNode* curr = new TreeNode(i);          // 注意节点一定要在内层循环生成，否则就成了一个节点，每次修改一下它的左右子树，那么最终的vector里面就会有好多相同的树
                    curr->left = left[l];
                    curr->right = right[r];
                    res.push_back(curr);
                }
            }
        }
        return res;
    }
};
