/**
 * 一上来能想到用两个指针，但是当两个指针移动的时候还需要记录相关字符出现了几次
 * 额外出现的不用管，但是如果再扔就不够了那就得把right指针右移了，于是用一个map记录还需要的个数，可以为负数
 * right指针右移的条件是requiredCnt > 0，当requiredCnt = 0时就需要把left指针左移了，requiredCnt是一共还需多少个字符
 */


class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        if (sLen == 0 || tLen == 0) {
            return "";
        }

        unordered_map<char, int> required;
        int requiredCnt = 0;
        for (char c : t) {
            required[c]++;
            ++requiredCnt;
        }

        int left = 0, right = -1;
        int minLen = INT_MAX, minLeft = 0;
        while (left < sLen && right < sLen) {
            if (requiredCnt > 0) {
                ++right;
                if (required.count(s[right]) == 1) {
                    if (required[s[right]] > 0) {
                        --requiredCnt;
                    }
                    --required[s[right]];
                }
            } else {
                int currLen = right - left + 1;
                if (minLen > currLen) {
                    minLen = currLen;
                    minLeft = left;
                }
                if (required.count(s[left]) == 1) {
                    if (required[s[left]] == 0) {
                        ++requiredCnt;
                    }
                    ++required[s[left]];
                }
                ++left;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }
        return s.substr(minLeft, minLen);
    }
};
