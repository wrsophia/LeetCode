/**
 * 其实就是看某个范围内的数字是否都大于边界，于是可以先定好一个边界，遍历的时候只用遍历一遍
 * 如果发现某个值小于边界了那么之前遍历过的就都不能要了，用这个小数作为新的边界，继续遍历
 */


class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        // find max position
        int maxPos = 0;
        for (int i = 0; i < n; ++i) {
            maxPos = flowers[i] > maxPos ? flowers[i] : maxPos;
        }
        vector<int> openDay (maxPos, INT_MAX);
        for (int i = 0; i < n; ++i) {
            openDay[flowers[i] - 1] = i + 1;
        }

        int day = INT_MAX;
        int left = 0, right = k + 1;
        for (int i = 0; i < maxPos; ++i) {    // 这个方法可以把时间复杂度降到O(n)
            if (openDay[i] < openDay[left] || openDay[i] <= openDay[right]) {
                if (i == right) {
                    day = min(day, max(openDay[left], openDay[right]));
                }
                left = i;
                right = left + k + 1;
            }
        }
        return day == INT_MAX ? -1 : day;

    }
};
