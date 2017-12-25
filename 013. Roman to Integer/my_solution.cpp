#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
罗马数字：正常情况下每遇到一个字符就是加上对应的数值，但是类似 IV = 5 - 1, IX = 10 - 1 是例外
所以在输入没有错的情况下，正常情况应该是左侧的字符不会小于右边的字符，如果出现这种情况就需要减去左侧的字符
我觉得设计罗马计数的人脑子有坑
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        
        int res = 0;
        int n = s.length();
        
        for (int i = 0; i < n - 1; ++i) {
            res += roman[s[i]] >= roman[s[i + 1]] ? roman[s[i]] : -roman[s[i]];
        }
        res += roman[s[n - 1]];
        
        return res;       
    }
};