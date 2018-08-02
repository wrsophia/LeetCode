/**
 * 一看就是一道dfs，但由于每个组合只出现一次(即每个小数组里数字是按大小顺序排列的)
 * 于是就可以给dfs传入这次的位置+1，作为下次的起始位置
 */


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> res;
        dfs(result, res, k, n, 1);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& res, int k, int n, int pos) {
        if (res.size() == k) {
            result.push_back(res);
            return;
        }

        for (int i = pos; i <= n; ++i) {
            res.push_back(i);
            dfs(result, res, k, n, i + 1);
            res.pop_back();
        }
    }
};
