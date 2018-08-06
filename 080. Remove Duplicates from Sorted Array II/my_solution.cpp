/*
 * 首先，不能直接把元素删掉，因为这样数组会自动申请新的空间，无法保证空间O(1)
 * 我们需要做的就是重新填充数组，记下来每个数出现的次数，多于两次就填两次，最后now的位置就是数组长度
 */


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int now = 0, left = 0, right = 0;
        int cnt = 0;

        while (right < n) {
            while (right < n && nums[right] == nums[left]) {
                ++right;
            }
            cnt = (left + 1 == right) ? 1 : 2;
            while (cnt--) {
                nums[now++] = nums[left];
            }
            left = right;
        }
        return now;
    }
};
