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
	int longestPalindrome(string s) {
		unordered_map<char, int> hash;
		for (auto it = s.begin(); it != s.end(); ++it) {
			hash[*it]++;
		}
		int oddCount = 0;
		int ans = 0;
		for (auto i : hash) {
			if (i.second & 1) {
				++oddCount;
				ans += i.second - 1;
			}
			else
				ans += i.second;
		}
		if (oddCount > 0)
			++ans;
		return ans;
	}
};