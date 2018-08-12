/**
 * 直接用二分法，每次分为 target 在前/后半部分呢，mid 在前/后半部分 这4种情况
 */


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int head = 0, tail = nums.size()-1;
        while (head <= tail) {
            int mid = head + (tail - head) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target > nums[tail]) {   // target in front
                if (nums[mid] > nums[tail]) {   // mid in front
                    if (target < nums[mid]) {
                        tail = mid - 1;
                    } else {   // mid in back
                        head = mid + 1;
                    }
                } else {  // mid in back
                    tail = mid - 1;
                }
            } else {   // target in back
                if (nums[mid] > nums[tail]) {   // mid in front
                    head = mid + 1;
                } else {   // mid in back
                    if (target > nums[mid]) {
                        head = mid + 1;
                    } else {
                        tail = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
