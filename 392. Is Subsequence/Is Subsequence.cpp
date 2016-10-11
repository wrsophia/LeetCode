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
	bool isSubsequence(string s, string t) {
		string::iterator s_it = s.begin(), t_it = t.begin();
		while (s_it != s.end())
		{
			while (*s_it != *t_it)
			{
				++t_it;
				if (t_it >= t.end())
					return false;
			}
			++s_it, ++t_it;
		}
		return true;
	}
};