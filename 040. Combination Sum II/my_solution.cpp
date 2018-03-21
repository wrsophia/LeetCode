#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
排好序有助于去重和节省时间
去重：在pop_back()之后不能放入值相同的元素
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> tmp;

        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, result, 0, tmp); 

        return result;
    }

    void dfs(vector<int>& candidates, int distance, vector<vector<int>>& result, int idx, vector<int>& tmp) {
    	if (distance == 0) {
    		result.push_back(tmp);
    		return;
    	}

    	for (int i = idx; i < candidates.size(); ++i) {
    		int val = candidates[i];
    			
    		if (val > distance) {
    			return;
    		}
    		tmp.push_back(candidates[i]);
    		dfs(candidates, distance - val, result, i + 1, tmp);
    		tmp.pop_back();
            
            while (i + 1 < candidates.size() && val == candidates[i + 1]) {
                ++i;
            }
    	}

    }
};