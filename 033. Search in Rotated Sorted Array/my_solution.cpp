#include <iostream>
#include <vector>
using namespace std;

/*
先找到最大的数字，然后两边各为增序数组，再在其中之一找target
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int n = nums.size();
        if (n == 0) {
            return -1;
        }
        
    	int max = find_max(nums);

    	return target < nums[0] ? find_target(nums, max + 1, n - 1, target) : find_target(nums, 0, max, target);        
    }

    int find_max(vector<int>& nums) {
    	int n = nums.size();

    	int left = 0, right = n - 1;
    	while (left < right) {
    		int mid = left + (right - left) / 2;

    		if (nums[mid] == nums[left]) {
    			break;
    		}

    		if (nums[mid] > nums[left]) {
    			left = mid;
    		} else {
    			right = mid - 1;
    		}
    	}
    	
    	return nums[left] > nums[right] ? left : right;
    }

    int find_target(vector<int>& nums, int left, int right, int target) {
    	while (left <= right) {
    		int mid = left + (right - left) / 2;

    		if (target == nums[mid]) {
    			return mid;
    		}

    		if (target < nums[mid]) {
    			right = mid - 1;
    		} else {
    			left = mid + 1;
    		}
    	}
    	return -1;
    }
};