#include <iostream>
#include <unordered_set>
using namespace std;

/*
用两个指针，当做滑动窗口，维持当前无重复字母的子串，用set记录元素是否被用过
用max_len记录历史最长子串的长度，如果要求是输出最长的子串而不是长度，只需再用一个字符串记录历史最长子串
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniqueChar;
        int len = 0;
        int max_len = 0;

        int idx_1 = 0, idx_2 = 0;
        while (idx_2 < s.length()) {
        	if (uniqueChar.find(s[idx_2]) == uniqueChar.end()) {  //该字母未出现过
        		++len;
        		max_len = len > max_len ? len : max_len;
        		uniqueChar.insert(s[idx_2]);
        		++idx_2;
        	} else {
        		do {
        			uniqueChar.erase(s[idx_1]);
        			--len;
        			++idx_1;
        			if (s[idx_1 - 1] == s[idx_2]) {  //为防止原来s[idx_1] = s[idx_2]时循环删下去
        				break;
        			}
        		} while (s[idx_1] != s[idx_2]);
        	}
        }
        return max_len;
    }
};