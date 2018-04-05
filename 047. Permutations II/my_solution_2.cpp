#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
这个方法就是去掉了只有不重复元素的new_nums数组，但是(如第41行)当某元素pop出来之后不能再把数值相同的元素加进去
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();    
        vector<vector<int>> result;
        vector<int> permutation;
        
        unordered_map<int, int> left;     
        for (int i = 0; i < n; ++i) {
            ++ left[nums[i]];
        }
        
        sort(nums.begin(), nums.end());
        
        dfs(nums, n, result, permutation, left);
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
                while (nums[i + 1] == nums[i]) {
                    ++i;
                }
            }
        }
    }
};