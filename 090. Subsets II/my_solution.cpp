/**
 * 还是个比较明显的dfs，唯一的问题在于，比如[1,3,2,4,2]，如何使之只有一个[1,2,3]又不放过[1,2,2]
 * 解决办法不是遇到相同的就跳过，而是pop_back()之后不能放入相同元素，于是while循环写在pop_back()之后
 */


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        for (int k = 0; k <= nums.size(); ++k) {
            dfs(res, tmp, nums, k, 0);
        }
        return res;

    }

    void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int k, int idx) {
        if (tmp.size() == k) {
            res.push_back(tmp);
        }

        for (int i = idx; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            dfs(res, tmp, nums, k, i + 1);
            tmp.pop_back();
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                ++i;
            }
        }
    }
};
