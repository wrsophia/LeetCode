#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {      
        int idx = 0;
        while (str[idx] == ' ' || str[idx] == '\t') {   // 去掉开头的空字符
            ++idx;
        }
        int flag = 1;
        if (str[idx] == '-') {
            flag = -1;
            ++idx;
        } else if (str[idx] == '+') {
            ++idx;
        }
        
        long res = 0;
        while (str[idx]) {
            int num = str[idx] - '0';
            if (num < 0 || num > 9) {    // 遇到非数字就返回
                return flag * res;
            }
            res = 10 * res + num;
            
            if (flag * res > INT_MAX) {
                return INT_MAX;
            } else if (flag * res < INT_MIN) {
                return INT_MIN;
            }
            ++idx;
        }
        return flag * res;
            
    }
};