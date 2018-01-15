#include <iostream>
using namespace std;

/*
如果做减法时间复杂度太高了，于是从二进制方向考虑。
如果把商写成二进制，那么它可以看成是许多个2的幂相加而得的
对dividend不断除以2，即右移，如果在第m+1次移位后小于divisor，那么商的最高位就是2^m
然后再对剩余数字(dividend - 2^m * divisor, 即divisor左移m位)做上述操作。如此循环直至剩余数字 < divisor
把每次循环得到的2的幂相加即为最终答案。
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }

        int sgn_dividend = (dividend >> 31) & 1;
        int sgn_divisor = (divisor >> 31) & 1;
        int sign_minus = sgn_dividend ^ sgn_divisor;
        
        unsigned int u_dividend = sgn_dividend ? ~dividend + 1 : dividend;
        unsigned int u_divisor = sgn_divisor ? ~divisor + 1 : divisor;
        
        int res = 0;  
        
        unsigned int tmp_dividend = u_dividend;
        
        while (tmp_dividend >= u_divisor) {
            int tmp_res = 1;
            unsigned int tmp = tmp_dividend >> 1;
            unsigned int tmp_divisor = u_divisor;
            
            while (tmp >= u_divisor) {
                tmp_res = tmp_res << 1;
                tmp = tmp >> 1;
                tmp_divisor = tmp_divisor << 1;
            }
            res += tmp_res;
            tmp_dividend -= tmp_divisor;                        
        }
                
        return sign_minus ? -res : res; 
    }
};