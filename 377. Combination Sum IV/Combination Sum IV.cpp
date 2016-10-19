#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;
		vector<int> solution(target + 1, 0);
		solution[0] = 1;
		for (int i = 1; i <= target; i++)
		{
			for (int obj : nums)
				if (obj <= i)
					solution[i] += solution[i - obj];
		}
		return solution[target];
	}
};

//follow up:
//�������������ӵ�0�ļ������֣�����1��-1����ô�����ᵽ���޴�