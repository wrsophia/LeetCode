#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
把从左到右整个看成一个大缸，那么如果左边和右边分别有一个1(或者大于1的树)，那么其实这中间就都能存住水(除了缸壁)
所以就从两端往中间找，每次矮的那个是wall，只有碰到更高的wall时才更新wall值，表名此时两指针中间的水可以存到以
此时wall值为水平线，每次存的水的高度为wall-lower
*/

class Solution {
public:
    int trap(vector<int>& height) {
    	int sum = 0;
    	int left = 0, right = height.size() - 1, wall = 0;

    	while (left < right) {
    		int lower = height[height[left] < height[right] ? left ++ : right --];
    		wall = max(wall, lower);
    		sum += wall - lower;
    	}
        return sum;
    }
};