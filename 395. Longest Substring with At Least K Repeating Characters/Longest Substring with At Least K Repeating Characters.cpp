#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

//对于每个切分的子串，统计每个字符出现的次数，若遇到不符的字符就从该处切开，递归继续统计

class Solution {
public:
	int longestSubstring(string s, int k) {
		string::iterator front = s.begin(), back = s.end();
		int maxLength = substrCore(s, front, back, k);
		return maxLength;
	}

	int substrCore(string s, string::iterator front, string::iterator back, int k) {
		if (back - front < k)
			return 0;
		unordered_map<char, int> submap;
		string::iterator it;
		int result = 0;
		for (it = front; it != back; it++)
			submap[*it]++;
		bool wholeStr = true;
		for (auto i : submap)
		{
			if (i.second < k)
			{
				wholeStr = false;
				break;
			}
		}
		if (wholeStr)
			return back - front;
		else
		{
			for (it = front; it != back; it++)
			{
				if (submap[*it] < k)
					break;
			}
			result = max(substrCore(s, front, it, k), substrCore(s, it + 1, back, k));
			return result;
		}
	}
};

int main()
{
	string s = "abcdedghijklmnopqrstuvwxyz";
	int k = 2;
	Solution sol;
	cout << sol.longestSubstring(s, k) << endl;
	system("pause");
	return EXIT_SUCCESS;
}
