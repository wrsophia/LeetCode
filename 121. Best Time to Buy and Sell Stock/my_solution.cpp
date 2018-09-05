/**
 * 新建一个数组保存差值，然后问题转化为最大连续子数组和
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        vector<int> profit(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            profit[i] = prices[i + 1] - prices[i];
        }

        int max = 0;
        int curr = 0;
        for (int i = 0; i < profit.size(); ++i) {
            curr += profit[i];
            if (curr < 0) {
                curr = 0;
            }

            max = curr > max ? curr : max;
        }
        return max;
    }
};
