#include <iostream>
#include <cstdlib>
using namespace std;

//如果低位是11就加1，如果低位是01就减1
//3和0x7fff是特殊情况

class Solution {
public:
	int integerReplacement(int n) {
		if (n == INT_MAX) {   //special case
			return 32;        //因为0x8000右移位的时候是以符号位1填补左侧的，于是循环永远不会结束，超时错误
		}
		int cnt = 0;
		while (n != 1) {
			if (n & 1) {
				if (n == 3) {    //special case
					cnt += 2;
					return cnt;
				}
				if (n & 0x02) {
					++n;
				}
				else {
					--n;
				}
			}
			else {
				n >>= 1;
			}
			++cnt;
		}
		return cnt;
	}
};