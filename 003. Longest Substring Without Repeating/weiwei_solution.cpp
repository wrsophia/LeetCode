#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        
        int start = 0, end = 0;
        bool in_window[256]  = {false};
        int ans = 1;
        in_window[s[0]] = true;
        
        while (++end < s.size()) {
            while (in_window[s[end]]) {
                in_window[s[start]] = false;
                ++start;
            }
            in_window[s[end]] = true;

            ans = max(ans, end-start+1);
        }
        
        return ans;
    }
};