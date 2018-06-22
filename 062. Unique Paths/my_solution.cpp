/**
 * 比较直观的思路是动态规划，不过对于这个题来说太小题大做了，这是个数学问题
 * 不管哪种走法，一共需要走 m-1 + n-1 步，其中有 m-1 个 ↓，n-1 个 →
 * 于是答案就是 C(m-1+n-1)(m-1)，考虑时间的话取 m 和 n 中较小的那个
 */


class Solution {
public:
    int uniquePaths(int m, int n) {
        int down = m - 1, right = n - 1;
        int allSteps = down + right;
        int min = down > right ? right : down;
        return combination(allSteps, min);
    }
    int combination(int m, int n) {
        long a = 1, b = 1;
        for (int i = n; i > 0; --i) {
            a *= m--;
            b *= n--;
        }
        return a / b;
    }
};
