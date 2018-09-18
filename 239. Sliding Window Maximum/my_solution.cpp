/**
 * 对于一个新来的数字，队里原有的数字都是它之前的了，所以，队里的某数如果比它小，那么再也不可能成为最大值了，于是就可以删掉了
 * 于是这个队列其实是一个降序排列的容器，比自己小的数字之所以要放进来是因为队头在最多k次之后是要被pop出去的，它后面的元素有可能成为下一个新队头
 * 考虑到队尾也需要删除元素，于是用一个双端队列deque，队里放的是idx，这样就可以省去不知道某数何时过期的麻烦
 */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0 || nums.size() == 0) {
            return vector<int> ();
        }
        if (k == 1) {
            return nums;
        }
        deque<int> maxItem;
        maxItem.push_back(0);
        vector<int> res;
        int maxIdx = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (i - k + 1 > maxItem.front()) {
                maxItem.pop_front();
            }
            while (!maxItem.empty() && nums[i] > nums[maxItem.back()]) {
                maxItem.pop_back();
            }
            maxItem.push_back(i);

            int idx = maxItem.front();
            if (i >= k - 1) {
                res.push_back(nums[idx]);
            }

        }
        return res;
    }
};
