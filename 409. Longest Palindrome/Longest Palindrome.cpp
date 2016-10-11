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

		}
	}
	bool isPalindrome(string str) {
		auto it_h = str.begin(), it_t = str.end() - 1;
		while (it_h < it_t) {
			if (*it_h != *it_t)
				return false;
			++it_h, --it_t;
		}
		return true;
	}
};