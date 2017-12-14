#include <iostream>
#include <string>
using namespace std;

/*
用两个指针分别放在相同字符的两端，因为相同的字符不管奇数偶数个一定都是回文
然后由这两端分别向两侧扩展，看最多能收入多少个，时间复杂度为O(n²)
我自己想的解法是反转字符串然后求最长公共子串，但是对于字符串abcdfcba就不能用
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int idx_left = 0;
        int max = 1;
        string::iterator it_left = s.begin(), it_right = it_left;

        while (it_left != s.end()) {
        	while ((it_right + 1) != s.end() && *(it_right + 1) == *it_left) {
        		++it_right;
        	}

        	string::iterator left = it_left - 1, right = it_right + 1;
        	while (left >= s.begin() && right < s.end() && *left == *right) {
        		--left;
        		++right;
        	};
        	if (right - ++left > max) {
        		max = right - left;
        		idx_left = left - s.begin();
        	}

        	it_left = ++it_right;
        }
        return s.substr(idx_left, max);
    }
};