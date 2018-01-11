#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.size() == 0) {
    		return 0;
    	}
    	int idx1 = 0, idx2 = idx1;
    	while (idx2 < nums.size()) {
    		while (idx2 < nums.size() && nums[idx2] == nums[idx1]) {
    			++idx2;
    		}
    		if (idx2 == nums.size()) {
    			break;
    		}
    		nums[++idx1] = nums[idx2++];
    	}
    	return idx1 + 1;
    }
};