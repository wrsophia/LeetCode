#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

//greedy
//cnt变化的时候是开始上升或下降的第一个元素，但实际用的是上升或下降的最后一个元素

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1)  return n;
		bool flag = NULL;
		int cnt = 1;
		for (int i = 1; i < n; ++i) {
			if (nums[i] > nums[i - 1] && (flag == NULL || !flag)) {
				flag = true;
				++cnt;
			}
			else if (nums[i] < nums[i - 1] && (flag == NULL || flag)) {
				flag = false;
				++cnt;
			}
		}
		return cnt;
	}
};

int main() {
	int arr[] = { 1,17,5,10,13,15,10,5,16,8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> nums(arr, arr + size);
	Solution sol;
	cout << sol.wiggleMaxLength(nums) << endl;	
	system("pause");
	return 0;
}
