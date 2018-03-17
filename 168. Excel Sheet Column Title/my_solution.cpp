#include <iostream>
#include <string>
using namespace std;

/*
其实就是26进制，但是有一点不一样的地方，就是当余数是0的时候，其实是余26
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        
        while (n > 0) {
            int r = n % 26;
            n = n /26;
            if (r == 0) {
                r = 26;
                -- n;
            }
            
            res = (char) ('A' + r - 1) + res;
        }
        
      return res;          
    }
};