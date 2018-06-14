class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int end = n - 1;
        while (end > 0 && s[end] == ' ') {
            --end;
        }

        for (int i = end; i >= 0; --i) {
            if (s[i] == ' ') {
                return end - i;
            }
        }
        return s[end] == ' ' ? 0 : end + 1;
    }
};
