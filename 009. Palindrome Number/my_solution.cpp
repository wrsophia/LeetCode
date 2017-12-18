#include <iostream>
using namespace std;

/*
利用回文翻转后与原值相等，不过这并不符合 no extra space
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {      // 答案认为符号也算在内，于是所有负数都不能使回文
            return false;
        }
        int x_copy = x;
        int tmp = 0;
        while (x_copy != 0) {
            tmp = 10 * tmp + x_copy % 10;
            x_copy /= 10;
        }
        return x == tmp;
    }
};