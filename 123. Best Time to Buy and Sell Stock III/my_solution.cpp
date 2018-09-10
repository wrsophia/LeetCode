/**
 * 两个transaction相当于把prices数组拆分成两个数组，每个数组分别计算一个maxPrice然后相加
 * 第一次遍历的时候可以把到每个点的maxPrice记录下来，然后再遍历每个点之后的那段的maxPrice，再相加
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int mp = 0, maxPrice = 0, currMin = prices[0];
        vector<int> dp(prices.size(), 0);
        for (int i = 0; i < prices.size(); ++i) {     // 先找到从idx=0开始的到所有位置的maxPrice
            currMin = min(currMin, prices[i]);
            mp = max(mp, prices[i] - currMin);
            dp[i] = mp;
        }
        maxPrice = dp[prices.size() - 1];

        for (int i = 1; i < prices.size() - 1; ++i) {      // 然后找从idx=i+1开始的数组的maxPrice，最终的maxPrice就是两个maxPrice相加
            if (dp[i] == 0 || dp[i] == dp[i - 1]) {
                continue;
            }
            currMin = prices[i + 1];
            mp = 0;
            for (int j = i + 1; j < prices.size(); ++j) {
                // find max in j...n-1
                currMin = min(currMin, prices[j]);
                mp = max(mp, prices[j] - currMin);
                maxPrice = max(maxPrice, dp[i] + mp);
            }
        }
        return maxPrice;
    }
};
