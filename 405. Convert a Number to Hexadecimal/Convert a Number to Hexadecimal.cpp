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

//���ù��������ʮ������ʲô���ö�����ת��Ϊʮ������
//ע�⸺�����������λ��Ҫ�÷���λ��1�������ģ�������Զ�����ᵽ0
//������һ��cnt����¼��λ������int 32bit������ƴΣ�

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