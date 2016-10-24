#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//维护一个窗口

class Solution {
public:
	int characterReplacement(string s, int k) {
		int start = 0, end = 0, maxCount = 0, maxLen = 0;
		int n = s.length();
		unordered_map<char, int> hash;
		for (; end < n; ++end) {
			++hash[s[end]];
			maxCount = max(maxCount, hash[s[end]]);
			if (end - start - maxCount + 1 > k) {        //if语句里不更新maxCount可以省略两个while循环	
				--hash[s[start]];				         //一个为使start++的循环，另一个为找确切的maxCount的循环
				++start;                			     //end和start同时后移，就类似于动态规划中的保存当前最大值
			}                                            //直到发现了更大的maxCount，才可以使仅end后移，更新maxLen
			maxLen = end - start + 1;
		}
		return maxLen;
	}
};