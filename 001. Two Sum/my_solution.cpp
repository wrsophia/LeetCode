#include <iostream>
#include <vector>
#include <pair>
#include <algorithm>
using namespace std;

/*
暴力解决的时间复杂度是 n^2，但如果是个排好序的数组，用两个指针分别从两头向中间移动，只需遍历一遍就能解决
但是排序数组需要 n*logn 的时间，于是总的时间复杂度为 n*logn
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // make pair: value and index
        vector<pair<int, int> > val_idx (nums.size());
    
        vector<int>::iterator it1 = nums.begin();
        vector<pair<int, int> >::iterator it2 = val_idx.begin();
    
        for (int i = 0; it2 != val_idx.end(); ++it1, ++it2, ++i) {
            *it2 = make_pair(*it1, i);
        }
        
        // sort val_index upon its first
        sort(val_idx.begin(), val_idx.end(), compare);
        
        // find the two elements
        vector<int> result;
        vector<pair<int, int> >::iterator it_left = val_idx.begin();
        vector<pair<int, int> >::iterator it_right = val_idx.end() - 1;
        
        while (it_left < it_right) {
            if ((*it_left).first + (*it_right).first == target) {
                result.push_back((*it_left).second);
                result.push_back((*it_right).second);
                break;
            } else if ((*it_left).first + (*it_right).first < target) {
                ++it_left;
            } else {
                --it_right;
            }
        }
        
        return result;       
    }
    
    static bool compare(pair<int, int> pair1, pair<int, int> pair2) {
        return pair1.first < pair2.first;
    }
};