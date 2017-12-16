#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows <= 1) return s;

            int n = s.size();
            string result(s);

            int i, j, pos = 0;
            int step = 2 * numRows - 2;
            bool flag = 0;
            for (i = 0; i < numRows; ++i) {
                if (i == 0 || i == numRows-1) {
                    for (j = i; j < n; j += step) {
                        result[pos++] = s[j];
                    }

                } else {
                    int right_step = 2 * i;
                    int left_step = step - right_step;
                    j = i;
                    flag = 0;
                    while (j < n) {
                        result[pos++] = s[j];

                        j += flag ? right_step : left_step;
                        flag = !flag;
                    }
                }
            }

            return result;
        }
};