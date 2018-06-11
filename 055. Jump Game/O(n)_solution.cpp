/**
 * 其实这道题的约束条件十分宽泛，只要某一点能跳的最大距离涵盖了最后一个点即可
 * 所以我们可以从头开始找历史能到的最大距离
 * 有一种情况是死局，可以提前结束循环，就是，当所有先前点都必须经过某点，而不能跳过它，而且在它这里还走不动了的情况
 * 即 max_jump = i + nums[i]
 */


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_jump = 0;

        for (int i = 0; i < n; ++i) {
            max_jump = max_jump < i + nums[i] ? i + nums[i] : max_jump;

            if (max_jump >= n - 1) {
                return true;
            }
            if (max_jump == i) {
                return false;
            }
        }

        return false;
    }
};
