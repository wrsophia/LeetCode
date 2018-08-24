/**
 * 我一开始的思路是，把之前的一堆点看成一个小数值点，新加入的点是一个大数值点，两个点的树有两种结构，于是 bst[n] = 2 * bst[n - 1]
 * 但是这个思路不对
 * 正确的思路是：把每个点k当一次根节点，把剩余节点分为>k的和<k的，于是以k为根节点的树有 bst[<k] * bst[>k] 种形状
 * 如果递归来做这道题，有很多会重算好几遍，浪费时间，于是考虑用一个数组把n之前的值都保存起来
 */


class Solution {
public:
    int numTrees(int n) {
        if (n == 0) {
            return 0;
        }

        vector<int> bst (n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            int num = 0;
            for (int head = 1; head <= i; ++head) {
                int left = head - 1;
                int right = i - head;
                num += bst[left] * bst[right];
            }
            bst[i] = num;
        }
        return bst[n];
    }
};
