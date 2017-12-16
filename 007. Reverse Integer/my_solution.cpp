#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0 || x == INT_MIN) {  // 这里比较坑，因为INT_MIN不能转换为相同数值的正数
            return 0;                  // INT_MAX = 0X7FFFFFFF = 2147483647, INT_MIN = 0x80000000 = -2147483648
        }                              // (对于64位编译器)
        
        bool minus = x < 0 ? true : false;
        if (minus) {
            x = -x;
        }
        
        long res = 0;                 // 另一个坑的地方在于，x是不会越界的，但反转后的有可能
                                      // 但是int型的res是无法判断是否越界的，因为溢出之后剩余的部分也一定是 <= INT_MAX 的    
        while (x % 10 == 0) {    // 去掉末尾的0
            x /= 10;
        }
        
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        
        if (res > INT_MAX) {
            return 0;
        }
            
        return minus ? -res : res;
    }
};