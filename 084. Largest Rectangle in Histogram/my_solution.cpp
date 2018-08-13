/**
 * 对于每一个height，分别找到它左边第一个比它小的和右边第一个比它小的位置，于是以该height为高度，面积为
 * heights[i] * (firstLessRight[i] - firstLessLeft[i] - 1)
 * 于是问题转化为如何快速找到左边和右边第一个比它小的位置
 */


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> firstLessRight (n, n);
        vector<int> firstLessLeft (n, -1);

        // find first less in the right
        for (int i = n - 2; i >= 0; --i) {
            int idx = i + 1;
            while (idx < n && heights[idx] >= heights[i]) {
                idx = firstLessRight[idx];
            }
            firstLessRight[i] = idx;
        }

        // find first less in the left
        for (int i = 1; i < n; ++i) {
            int idx = i - 1;
            while (idx >= 0 && heights[idx] >= heights[i]) {
                idx = firstLessLeft[idx];
            }
            firstLessLeft[i] = idx;
        }

        int area = 0;
        for (int i = 0; i < n; ++i) {
            area = max(area, (firstLessRight[i] - firstLessLeft[i] - 1) * heights[i]);
        }
       return area;
    }
};
