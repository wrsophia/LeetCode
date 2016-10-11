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


class Solution {
public:
	string addStrings(string num1, string num2) {
		string ans = "";
		int flag = 0;
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int dig1 = 0, dig2 = 0;
		auto it1 = num1.begin(), it2 = num2.begin();
		while (it1 != num1.end() && it2 != num2.end()) {
			int tmp = *it1 - '0' + *it2 - '0' + flag;
			flag = tmp / 10;
			tmp %= 10;
			ans.push_back(tmp + '0');
			++it1, ++it2;
		}
		while (it1 != num1.end()) {
			int tmp = *it1 - '0' + flag;
			flag = tmp / 10;
			tmp %= 10;
			ans.push_back(tmp + '0');
			++it1;
		}
		while (it2 != num2.end()) {
			int tmp = *it2 - '0' + flag;
			flag = tmp / 10;
			tmp %= 10;
			ans.push_back(tmp + '0');
			++it2;
		}
		if (flag == 1)  ans += '1';
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	string num1 = "332589", num2 = "390547135";
	Solution sol;
	cout << sol.addStrings(num1, num2) << endl;
	system("pause");
	return EXIT_SUCCESS;
}
