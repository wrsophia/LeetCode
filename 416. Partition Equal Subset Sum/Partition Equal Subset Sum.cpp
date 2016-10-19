#include <iostream>
#include <cstdlib>
#include <vector>
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
		for (int i = 0; i < n; ++i) {  
            		for (int j = sum; j >= 1; --j) {  
                		if (j >= nums[i]) {  
                    			dp[j] = max(dp[j], nums[i] + dp[j - nums[i]]);  
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
