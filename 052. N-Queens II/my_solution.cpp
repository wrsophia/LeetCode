
/**
 *和之前那个差不多，都得把dfs跑一边，不过这次不用把结果输出了，只用统计一个个数就行了
 */


class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> queenArr;
        vector<bool> used (n, false);

        dfs(res, n, queenArr, used);

        return res;
    }

    void dfs(int& res, int n, vector<int>& queenArr, vector<bool>& used) {
        if (queenArr.size() == n) {
            ++res;
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

};

