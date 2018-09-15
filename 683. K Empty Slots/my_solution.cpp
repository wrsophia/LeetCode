/**
 * 这个题就是把flowers转换为position为下标，day为值的一个数组，然后问题转化为
 * 给出一个最小的maxDay，使得与它相隔k个position的地方，它们中间的数字都大于它们
 * 我这个找k个大于它们的数的方法不太好，可以看另外一个版本
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
        for (int i = 0; i < maxPos - k - 1; ++i) {
            int day1 = openDay[i], day2 = openDay[i + k + 1];
            int maxDay = max(day1, day2);

            int cnt = 0;
            for (int j = i + 1; j <= i + k; ++j) {
                if (openDay[j] < maxDay) {
                    break;
                }
                ++cnt;
            }
            if (cnt == k) {
                day = maxDay < day ? maxDay : day;
            }
        }
        if (day < INT_MAX) {
            return day;
        } else {
            return -1;
        }

    }
};
