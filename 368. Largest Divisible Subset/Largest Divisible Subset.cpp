#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.empty()) {
			return nums;
		}
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> dp(n, 1);
		vector<int> index(n);
		for (int i = 0; i < n; ++i) {
			index[i] = i;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					index[i] = j;
				}
			}
		}
		deque<int> que;		
		int size = 0, indx = 0;
		for (int i = 0; i < n; ++i) {
			if (dp[i] > size) {
				size = dp[i];
				indx = i;
			}
		}
		while (index[indx] != indx) {
			que.push_front(nums[indx]);
			indx = index[indx];
		}
		que.push_front(nums[indx]);
		
		vector<int> ans(que.begin(), que.end());
		return ans;

	}
};

int main() {
	int arr[] = { 2,1,4,9 };
	vector<int> nums(arr, arr + 4);
	Solution sol;
	vector<int> res = sol.largestDivisibleSubset(nums);
	for (int i : res) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}