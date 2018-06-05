
/**
N皇后的规则是同一行、同一列、同一对角线上不能有两个皇后
如果用一个数组，queenArr[i]表示第i列第queenArr[i]行上有一个皇后，并且queenArr中的元素不能重复，那么就直接解决了行和列的问题
对角线有两种情况，可以抽象为queenArr[i] + i != queenArr[j] + j 和 queenArr[i] - i != queenArr[j] - j
*/



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queenArr;
        vector<bool> used (n, false);

        dfs(res, n, queenArr, used);

        return res;
    }

    void dfs(vector<vector<string>>& res, int n, vector<int>& queenArr, vector<bool>& used) {
        if (queenArr.size() == n) {
            res.push_back(convert(queenArr));
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                int m = queenArr.size();
                bool valid = true;

                for (int j = 0; j < m; ++j) {
                    if (queenArr[j] + j == i + m || queenArr[j] - j == i - m) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    used[i] = true;
                    queenArr.push_back(i);
                    
                    dfs(res, n, queenArr, used);
                    
                    used[i] = false;
                    queenArr.pop_back();
                }
            }
        }
    }

    vector<string> convert(vector<int> queenArr) {
        int n = queenArr.size();

        string init (n, '.');
        vector<string> queens (n, init);

        for (int i = 0; i < n; ++i) {
            queens[queenArr[i]][i] = 'Q';
        }

        return queens;
    }
};
