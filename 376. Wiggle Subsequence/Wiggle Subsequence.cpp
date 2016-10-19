#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

//greedy
//cnt�仯��ʱ���ǿ�ʼ�������½��ĵ�һ��Ԫ�أ���ʵ���õ����������½������һ��Ԫ��

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1)  return n;
		int idx = 1;
		while (idx < n && nums[idx] == nums[0]) ++idx;
		bool flag;
		if (nums[idx] > nums[0]) flag = true;
		else flag = false;
		
		int cnt = 1;
		for (int i = idx; i < n; ++i) {
			if (nums[i] > nums[i - 1] && flag) {
				flag = false;
				++cnt;
			}
			else if (nums[i] < nums[i - 1] && !flag) {
				flag = true;
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
