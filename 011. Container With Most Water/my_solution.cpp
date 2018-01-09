#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
    	int maxArea = 0;
    	int n = height.size();

    	int left = 0, right = n - 1;

    	while (left < right) {
    		int shorter = height[left] <= height[right] ? height[left] : height[right];

    		int area = shorter * (right - left);
    		maxArea = area > maxArea ? area : maxArea;

    		while (left < right && height[left] <= shorter) {
    			++left;
    		}

    		while (left < right && height[right] <= shorter) {
    			--right;
    		}
    	}
        return maxArea;
    }
};