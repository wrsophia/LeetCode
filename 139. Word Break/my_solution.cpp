/**
 * 思路是dp
 */


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string word : wordDict) {
            words.insert(word);
        }

        int len = s.length();
        vector<bool> valid(len + 1, false);
        valid[0] = true;
        for (int i = 1; i <= len; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (valid[j] && words.count(s.substr(j, i - j))) {
                    valid[i] = true;
                    break;
                }
            }
        }
        return valid[len];
    }
};
