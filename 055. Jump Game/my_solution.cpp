class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> available (n, false);
        available[0] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1, dist = 1; j >= 0; --j, ++dist) {
                if (available[j] && nums[j] >= dist) {
                    available[i] = true;
                    break;
                }
            }
        }
        return available[n - 1];
    }
};
