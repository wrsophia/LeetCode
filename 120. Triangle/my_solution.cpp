/**
 * 很多题一上来的思路就是从前向后，如果感觉这样做不出来可以考虑一下从后向前
 * 比较显然用dp来做，直观的是一个二维dp，如果我知道了第k+1行第i个数到bottom的最小和，那么第k行第i个数到bottom的最小和就是
 * dp[k][i] = min(dp[k + 1][i], dp[k + 1][i + 1]) + triangle[k][i]
 * 但是，当知道了第k行的dp值时，第k+1行的dp值就没有用了，于是其实可以用一个一维数组来保存，于是递推式变为
 * dp[i] = min(dp[i], dp[i + 1]) + triangle[row][i]
 * 最后dp[0]的值就是从最顶上开始的最小和
 */


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];

        for (int row = n - 2; row >= 0; --row) {
            for (int i = 0; i <= row; ++i) {
                dp[i] = min(dp[i], dp[i + 1]) + triangle[row][i];
            }
        }
        return dp[0];
    }
};
