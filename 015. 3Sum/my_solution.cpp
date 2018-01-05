#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
联想到之前的找出和为定值的两个数，可以用三个指针，每次把最左边的数的取负当做另外两个数的和，找出这两个数
需要注意的是重复数组的出现不止需要考虑第二、三个数，第一个数的重复也需要考虑
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> vec;

        int n = nums.size();
        if (n < 3) {
        	return result;
        }

        sort(nums.begin(), nums.end());
        int sum = INT_MAX;

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && sum == -nums[i]) {  // 要考虑第一个数连着相等的情况，会出现重复数组
                continue;
            }
        	sum = -nums[i];
        	int j = i + 1, k = n - 1;
        	while (j < k) {
        		if (nums[j] + nums[k] == sum) {
        			vec.push_back(nums[i]);
        			vec.push_back(nums[j]);
        			vec.push_back(nums[k]);
        			result.push_back(vec);

        			vec.clear();
        			do {               // 考虑第二个、第三个数连着重复的情况，也会出现重复数组
        				++j;
        			} while (j < k && nums[j] == nums[j - 1]);
        			do {
        				--k;
        			} while (j < k && nums[k] == nums[k + 1]);
        			
        		} else if (nums[j] + nums[k] < sum) {
        			++j;
        		} else {
        			--k;
        		}
        	}
        }
        return result;

    }
};