/**
 * 这个题的突破口在于，如果dp[i - 1][j] = false 或者dp[i][j - 1] = false，那么之后的所有i, j就不可能为true了
 * 于是地推公式就是 dp[i][j] = (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) || (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1])
 * 并且把 dp[0][0] 设置成 true, 又能方便后面的推算，又能在三个空串的时候返回true
 */


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length();
        if (l1 + l2 != s3.length()) {
            return false;
        }
        vector<vector<bool>> dp (l1 + 1, vector<bool> (l2 + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= l1; ++i) {
            dp[i][0] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][0];
        }
        for (int i = 1; i <= l2; ++i) {
            dp[0][i] = (s2[i - 1] == s3[i - 1]) && dp[0][i - 1];
        }

        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                dp[i][j] = (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) || (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]);
            }
        }
        return dp[l1][l2];
    }
};
