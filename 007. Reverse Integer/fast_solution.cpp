#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            int temp = ans * 10 + x % 10;  // 这个之所以正确是 x mod n 符号和 x 相同
            if (temp / 10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
    }
};