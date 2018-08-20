/**
 * 比较明显的dp，需要注意的是对0的处理，以及如果 dp[i] = 0 时就不用往下看了，因为后面都会是0
 */


class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        vector<int> dp (n + 1, 1);

        for (int i = 2; i <= n; ++i) {
            dp[i] = (s[i - 1] == '0' ? (validLetter(s[i - 2], s[i - 1]) ? dp[i - 2] : 0)
                     : dp[i - 1] + (validLetter(s[i - 2], s[i - 1]) ? dp[i - 2] : 0));
            if (dp[i] == 0) {
                return 0;
            }
        }

        return dp[n];
    }

    bool validLetter(char c1, char c2) {
        int a = c1 - '0';
        int b = c2 - '0';
        return !(a == 0) && (10 * a + b <= 26);
    }
};
