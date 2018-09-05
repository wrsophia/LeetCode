/**
 * 还是创建一个差值数组，然后把所有>0的项加起来
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
        for (int i = 0; i < profit.size(); ++i) {
            if (profit[i] > 0) {
                max += profit[i];
            }
        }
        return max;
    }
};
