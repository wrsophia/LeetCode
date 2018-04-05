#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
dfs，用一个map记录数组元素是否用过，每次都从头开始找第一个没用过的，放进去，然后继续dfs
然后每次dfs结束都要把该元素pop出来，放下一个元素
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> permutation;
        unordered_map<int, int> used;
        
        for (int i = 0; i < n; ++i) {
            used[nums[i]] = 0;
        }
        
        dfs(nums, result, permutation, used);
        return result;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& permutation, unordered_map<int, int>& used) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[nums[i]] == 0) {
                permutation.push_back(nums[i]);
                used[nums[i]] = 1;
                dfs(nums, result, permutation, used);
                permutation.pop_back();
                used[nums[i]] = 0;
            }
        }
    }
};