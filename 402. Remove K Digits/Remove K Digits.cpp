#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

//ɾ����������ͷ��ʼ���������ĳһλ������һλ����ô��Ӧ��ɾ����һλ����������һλС��ɾ�����һλ
//�����Ҫɾ���ַ�����ͷ��0������Ҫ���ǿմ��������

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