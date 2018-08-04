/**
 * 主体部分和上一题很相似，只不过变化的数组变成下标了
 */


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for (int i = 0; i <= nums.size(); ++i) {
            combine(nums, result, i);
        }
        return result;
    }

    void combine(vector<int>& nums, vector<vector<int>>& result, int k) {
        int n = nums.size();
        vector<int> res(k, 0);
        vector<int> idx(k, 0);

        if (k == 0) {
            result.push_back(res);
            return;
        }

        int i = 0;
        while (i >= 0) {
            ++idx[i];
            if (idx[i] > n) {
                --i;
            } else{
                res[i] = nums[idx[i] - 1];
                if (i == k - 1) {
                    result.push_back(res);
                } else {
                    ++i;
                    idx[i] = idx[i - 1];
                }
            }
        }
    }
};
