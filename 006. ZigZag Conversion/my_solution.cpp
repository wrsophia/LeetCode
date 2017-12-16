#include <iostream>
#include <string>
using namespace std;

/*
每隔一定的间隔取一个字母, 模 (2 * numRows - 2)
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {   // 这个是为防止 line 19 进入无限循环
            return s;
        }
        int n = s.length();
        char res[n + 1];
        int idx = 0;
        
        for (int i = 0; i < s.length(); i += (2 * numRows - 2)) {
            res[idx++] = s[i];         // 第1行和第n-1行和其它不一样，单独考虑
        }
        
        for (int i = 1; i < numRows - 1; ++i) {
            int k = i;
            int j = 2 * numRows - 2 - i;
            
            while (j < s.length()) {
                res[idx++] = s[k];
                res[idx++] = s[j];
                k += (2 * numRows - 2);
                j += (2 * numRows - 2);
            }
            if (k < s.length()) {
                res[idx++] = s[k];
            }            
        }
        
        for (int i = numRows - 1; i < s.length(); i += (2 * numRows - 2)) {
            res[idx++] = s[i];
        }
        
        res[idx] = '\0';
        return string(res);
    }
};