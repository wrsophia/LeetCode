#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

//水塘抽样

class Solution {
public:
	Solution(vector<int> nums) {
		number = nums;
	}

	int pick(int target) {
		int alpha = 1;
		int resIndex;
		for (int i = 0; i < number.size(); ++i) {
			if (number[i] == target) {
				if (rand() % (++alpha) == 0)
					resIndex = i;
			}
		}
		return resIndex;
	}
private:
	vector<int> number;
};

int main() {
	int arr[] = { 1,2,3,3,5,2,1,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> nums(arr, arr + n);
	Solution sol(nums);
	cout << sol.pick(5) << endl;
	system("pause");
	return 0;

}
