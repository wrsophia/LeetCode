#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
和17题一样的思路，dfs
为防止出现如 [2,2,3], [2,3,2], [3,2,2] 这样的重复，需要在dfs中加入索引这个参数
然后，为了节约时间，进行排序
*/


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        
        dfs(target, candidates, 0, tmp, res);
        return res;
        
    }
    
    void dfs(int target, vector<int>& candidates, int idx, vector<int> tmp, vector<vector<int> >& res) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        
        for (int i = idx; i < candidates.size(); ++i) {
            if (target < candidates[i]) {
                return;
            }
            tmp.push_back(candidates[i]);
            dfs(target - candidates[i], candidates, i, tmp, res);
            tmp.pop_back();
        }
    }
};