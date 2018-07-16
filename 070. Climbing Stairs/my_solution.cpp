/**
 * 就是斐波那契数列
 */


class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i = 1; i < n; ++i) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
};
