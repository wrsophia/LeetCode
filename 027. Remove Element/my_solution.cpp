#include <iostream>
#include <vector>
using namespace std;

/*
统计从idx=0开始不等于val的个数，在该个数的位置放上不等于val的数字
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int len = 0;
    	for (int i = 0; i < nums.size(); ++i) {
    		if (nums[i] != val) {
    			nums[len++] = nums[i];
    		}
    	}
    	return len;        
    }
};