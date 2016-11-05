#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		int head = 1, tail = num;
		while (head <= tail)
		{
			int mid = head + (tail - head) / 2;
			if ((num % mid == 0) && (mid == num / mid))
				return true;
			else if (mid < num / mid)
				head = mid + 1;
			else
				tail = mid - 1;
		}
		return false;
	}
};