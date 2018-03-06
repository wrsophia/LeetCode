#include <iostream>
#include <vector>
using namespace std;

/*
此题就是相当于把“数字”往大调，那么当最后两个数字是升序的时候就很简单了，只需一步操作就够了
那么反过来想，当后面一直是降序的时候，找到第一个升序的点，调大数字就只能调大该点，而调大的方法就是，
找到后面第一个比它大的数，交换，然后后面的数字变成升序(即把后面的数组反转)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	if (nums.size() < 2) {
    		return;
    	}

    	int desc_head = nums.size() - 1;

    	while (desc_head > 0 && nums[desc_head - 1] >= nums[desc_head]) {
    		-- desc_head;
    	}

    	if (desc_head > 0) {
    		int former = desc_head - 1;
    		int first_larger = desc_head;

    		while (first_larger < nums.size() && nums[first_larger] > nums[former]) {
    			++ first_larger;
    		}
    		-- first_larger;
    		swap(nums[former], nums[first_larger]);
    	}

    	reverse_from(nums, desc_head);
        
    }

    void reverse_from(vector<int>& nums, int begin) {
    	int end = nums.size() - 1;

    	while (end > begin) {
    		swap(nums[begin], nums[end]);

    		++begin, --end;
    	}
    }

    void swap(int& p1, int& p2) {
    	int tmp = p1;
    	p1 = p2;
    	p2 = tmp;
    }
};