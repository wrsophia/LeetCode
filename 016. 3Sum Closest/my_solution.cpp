#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
和上一题一样的思路，只不过变成记录最短距离
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        int min_distance = INT_MAX;
        
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int temp_sum = target - nums[i];            
            int j = i + 1, k = n - 1;
            while (j < k) {
                int temp = nums[j] + nums[k];
                if (temp == temp_sum) {
                    return target;
                } else if (temp < temp_sum) {
                    if (distance(temp, temp_sum) < min_distance) {
                        min_distance = distance(temp, temp_sum);
                        sum = nums[i] + temp;
                    }
                    ++j;
                } else {
                    if (distance(temp, temp_sum) < min_distance) {
                        min_distance = distance(temp, temp_sum);
                        sum = nums[i] + temp;
                    }
                    --k;
                }
            }
            
        }
        return sum;
    }
    
    int distance(int num1, int num2) {
        int diff = num1 - num2;
        return diff >= 0 ? diff : -diff;
    }
};