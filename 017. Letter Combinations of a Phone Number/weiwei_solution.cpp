#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
dfs, 每一层(比如第i层)都是对第i个数字对应的字母的遍历
于是for循环需要做的就是遍历字母，对于每个字母再进行一次dfs
*/

class Solution {
public:
    string table[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() <= 0) return res;
        
        string temp;
        dfs(digits, 0, temp, res);
        return res;
    }
    
    void dfs (const string &digits, int idx_digits, string temp, vector<string> &res) {
        if (idx_digits == digits.length()) {
            res.push_back(temp);
            return;
        }
        
        string lettes = table[digits[idx_digits] - '0'];
        for (int j = 0; j < lettes.length(); ++j) {
            dfs(digits, idx_digits+1, temp+lettes[j], res);  // 这样写就能避免 push_back() 和 pop_back()
        }
    }
};