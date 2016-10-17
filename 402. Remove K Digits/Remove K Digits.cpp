#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

//删除方法：从头开始，如果发现某一位比它下一位大，那么就应该删掉这一位，若都比下一位小则删除最后一位
//最后还需要删除字符串开头的0，并且要考虑空串的情况。

class Solution {
public:
	string removeKdigits(string num, int k) {
		string::iterator it;
		for (int i = 0; i < k; ++i) {
			it = num.begin();
			while (it != num.end() - 1 && *it <= *(it + 1)) {
				++it;
			}
			it = num.erase(it);
		}
		if (!num.empty()) {
			it = num.begin();
			while (num.size() > 1) {
				if (*it != '0')
					break;
				it = num.erase(it);
			}
			return num;
		}
		return "0";
	}
};

int main() {
	stringstream ss;
	string s = "00";
	cout << s << endl;
	int num;
	ss << s;
	ss >> num;
	cout << num << endl;
	ss << num;
	ss >> s;
	cout << s << endl;
	system("pause");
	return 0;
}