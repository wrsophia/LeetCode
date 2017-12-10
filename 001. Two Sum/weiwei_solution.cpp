#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
威威的解法，利用hash map查询 O(1) 的时间复杂度，遍历数组，没遇到一个元素就在map中找有没有另一个数
这样时间复杂度就降为 O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> val_idx;
        
        vector<int>::iterator it = nums.begin();
        for (int i = 0; it != nums.end(); ++it, ++i) {
            unordered_map<int, int>::iterator got = val_idx.find(target - *it);
            if (got != val_idx.end()) {
                result.push_back(got->second);
                result.push_back(i);
                break;
            } else {
                val_idx[*it] = i;
            }
        }
        return result;
    }
};





