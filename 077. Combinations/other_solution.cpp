/**
 * 这个方法有点类似手动解这道题的方法
 */


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> res(k, 0);

        int i = 0;
        while (i >= 0) {
            ++res[i];
            if (res[i] > n) {    // 注意这个if和下面的if顺序不能互换
                --i;
            } else if (i == k - 1) {
                result.push_back(res);
            } else {
                ++i;
                res[i] = res[i - 1];
            }
        }

        return result;
    }
};
