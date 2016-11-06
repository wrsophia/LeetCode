#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

/*
最后一个字符必须是'#'，中间不能出现'#'比数字多的情况，遍历完之后'#'要比数字多一个
*/

class Solution {
public:
	bool isValidSerialization(string preorder) {
		int len = preorder.size();
		if (len <= 0) return false;
		if (preorder[len - 1] != '#') return false;
		int nodes = 0, nulls = 0, s = 0, e = 0;
		while (e < len - 1) {
			while (e < len - 1 && preorder[e] != ',') ++e;
			string now = preorder.substr(s, e - s);
			if (now == "#") ++nulls;
			else ++nodes;
			if (nulls > nodes) return false;
			s = ++e;
		}
		return nulls == nodes;
	}
};

int main() {
	string test = "9,3,4,#,#,1,#,#,2,#,6,#,#";
	Solution sol;
	cout << boolalpha << sol.isValidSerialization(test) << endl;
	system("pause");
	return 0;
}