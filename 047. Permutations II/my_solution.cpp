#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
这个方法比较傻，先统计一下每个元素出现几次，然后再去重，然后再对去重后的数组进行dfs
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();    
        vector<vector<int>> result;
        vector<int> permutation;
        if (n == 0) {
            result.push_back(permutation);
            return result;
        }
        
        unordered_map<int, int> left;     
        for (int i = 0; i < n; ++i) {
            ++ left[nums[i]];
        }
        
        sort(nums.begin(), nums.end());
        vector<int> new_nums;
        int prev = nums[0];
        new_nums.push_back(prev);
        for (int i = 1; i < n; ++i) {
            if (nums[i] != prev) {
                prev = nums[i];
                new_nums.push_back(prev);
            }
        }
        
        dfs(new_nums, n, result, permutation, left);
        return result;
    }
    
    void dfs(vector<int>& nums, int n, vector<vector<int>>& result, vector<int>& permutation, unordered_map<int, int>& left) {
        if (permutation.size() == n) {
            result.push_back(permutation);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (left[nums[i]] > 0) {
                permutation.push_back(nums[i]);
                -- left[nums[i]];
                dfs(nums, n, result, permutation, left);
                permutation.pop_back();
                ++ left[nums[i]];
            }
        }
    }
};