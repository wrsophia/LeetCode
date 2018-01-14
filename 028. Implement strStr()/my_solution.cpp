#include <iostream>
#include <string>
using namespace std;

/*
注意如果出现像15行for循环里的两个length()相减的情况，一定要用12，13行的方法，先把length转成int
因为.length()是无符号的，如果相减如果是负数则会成为一个非常大的数，就会超时
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
    	int haystack_len = haystack.length();
    	int needle_len = needle.length();

        for (int i = 0; i <= (haystack_len - needle_len); ++i) {
        	if (isSub(haystack, needle, i)) {
        		return i;
        	}
        }
        return -1;
    }

    bool isSub(string haystack, string needle, int idx) {
    	for (int i = 0; i < needle.length(); ++i) {
    		if (idx + i >= haystack.length()) {
    			return false;
    		}
    		if (haystack[idx + i] != needle[i]) {
    			return false;
    		}
    	}
    	return true;
    }
};