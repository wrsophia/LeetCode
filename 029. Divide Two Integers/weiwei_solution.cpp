#include <iostream>
using namespace std;

/*
这种写法就很吊了，不愧大神
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        
        int mask = 1 << 31;
        int sign = (dividend ^ divisor) & mask;
               
        int sgn_dividend = (dividend & mask) >> 31;
        int sgn_divisor = (divisor & mask) >> 31;
        int sign_minus = sgn_dividend ^ sgn_divisor;
        
        unsigned int u_dividend = sgn_dividend ? ~dividend + 1 : dividend;
        unsigned int u_divisor = sgn_divisor ? ~divisor + 1 : divisor;
        
        if (divisor == 1 || divisor == -1) {
            return divisor * (int)u_dividend;
        }
        
        int res = 0;  

        if (u_divisor == 2) return !sign_minus ? u_dividend>>1 : -(u_dividend>>1);
        unsigned fac = u_divisor, bit = 1;
        while (fac < u_dividend) {
            fac <<= 1;
            bit <<= 1;
        }
        
        unsigned left = u_dividend;
        while (left >= u_divisor) {
            if (fac <= left) {
                left -= fac;
                res |= bit;
            }            
            fac >>= 1;
            bit >>= 1;
        }

        return sign | res;
    }
};