#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;


class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
		}
		if ((sum & 1) == 1) return false;
		sum = sum >> 1;
		vector<int> dp(sum + 1, 0);
		for (int i = 1; i <= sum; ++i) {
			for (int j = n - 1; j >= 0; --j) {
				if (i >= nums[j]) {
					dp[i] = max(dp[i], dp[i - nums[j]] + nums[j]);
				}
			}
		}
		return dp[sum] == sum;
	}
};

int main() {
	int arr[] = { 1, 5, 11, 5 };
	vector<int> nums(arr, arr + 4);
	Solution sol;
	cout << boolalpha << sol.canPartition(nums) << endl;
	system("pause");
	return EXIT_SUCCESS;
}