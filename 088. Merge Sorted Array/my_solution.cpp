/**
 * 考虑到nums1的后部都是空的，而数组的最大元素必然出现在m+n-1的位置，于是考虑从后往前填充nums1，这样能保证不丢失元素
 */


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1;
        int i = m + n - 1;
        while (i >= 0) {
            if (idx1 < 0) {
                nums1[i--] = nums2[idx2--];
            } else if (idx2 < 0) {
                nums1[i--] = nums1[idx1--];
            } else {
                if (nums1[idx1] > nums2[idx2]) {
                    nums1[i--] = nums1[idx1--];
                } else {
                    nums1[i--] = nums2[idx2--];
                }
            }
        }
    }
};
