/**
 * 如果你有了 n = n - 1 时的排列，那么 n = n 时的排列就是前面的数字(二进制)开头加个1，因为前面的数字已经天然形成了相邻两数只有一位不同
 * 但是还要注意是倒序，因为再刚要开始加1的时候只能把前一个数字的开头加上1
 */


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);

        for (int i = 0; i < n; ++i) {
            int size = res.size();
            for (int k = size - 1; k >= 0; --k) {
                res.push_back(res[k] | 1 << i);
            }
        }
        return res;
    }
};
