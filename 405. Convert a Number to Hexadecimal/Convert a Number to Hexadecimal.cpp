#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;

//不用管这个数字十进制是什么，用二进制转换为十六进制
//注意负数的情况右移位是要用符号位‘1’来补的，所以永远都不会到0
//于是用一个cnt来记录移位次数（int 32bit，最多移次）

class Solution {
public:
	string toHex(int num) {
		string hex = "0123456789abcdef";
		string ans = "";
		int cnt = 0;
		while (num != 0 && cnt++ < 8) {
			ans.push_back(hex[num & 15]);
			num >>= 4;
		}
		reverse(ans.begin(), ans.end());
		if (ans.empty()) {
			ans = "0";
		}
		return ans;
	}
};

int main() {
	int num = -1;
	Solution sol;
	cout << sol.toHex(num) << endl;
	system("pause");
	return 0;
}