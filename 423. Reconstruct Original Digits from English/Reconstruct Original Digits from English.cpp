#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

//�ȴ�ֻ���ֹ�һ�ε���ĸ��ʼ��0�е�z��2�е�w��4�е�u��6�е�x��8�е�g
//Ȼ���ٿ���ȥ��������֮��ʣ�µ�������ĳ����ĸֻ����һ�ε������1��3��5��7
//�����9

class Solution {
public:
	string originalDigits(string s) {
		unordered_map<char, int> hash;
		auto it = s.begin();
		while (it != s.end()) {
			++hash[*it];
			++it;
		}
		multiset<char> num;
		while (!hash.empty()) {
			if (hash['z'] > 0) {
				num.insert('0');
				--hash['z'], --hash['e'], --hash['r'], --hash['o'];
			}
			else if (hash['w'] > 0) {
				num.insert('2');
				--hash['t'], --hash['w'], --hash['o'];
			}
			else if (hash['u'] > 0) {
				num.insert('4');
				--hash['f'], --hash['o'], --hash['u'], --hash['r'];
			}
			else if (hash['x'] > 0) {
				num.insert('6');
				--hash['s'], --hash['i'], --hash['x'];
			}
			else if (hash['g'] > 0) {
				num.insert('8');
				--hash['e'], --hash['i'], --hash['g'], --hash['h'], --hash['t'];
			}
			else if (hash['o'] > 0) {
				num.insert('1');
				--hash['o'], --hash['n'], --hash['e'];
			}
			else if (hash['r'] > 0) {
				num.insert('3');
				--hash['t'], --hash['h'], --hash['r'], --hash['e'], --hash['e'];
			}
			else if (hash['f'] > 0) {
				num.insert('5');
				--hash['f'], --hash['i'], --hash['v'], --hash['e'];
			}
			else if (hash['v'] > 0) {
				num.insert('7');
				--hash['s'], --hash['e'], --hash['v'], --hash['e'], --hash['n'];
			}
			else if (hash['i'] > 0) {
				num.insert('9');
				--hash['n'], --hash['i'], --hash['n'], --hash['e'];
			}
			else break;
 		}
		string ans(num.begin(), num.end());
		return ans;
	}
};

int main() {
	string s = "owoztneoer";
	Solution sol;
	cout << sol.originalDigits(s) << endl;

	multiset<char> ms;
	ms.insert('b');
	ms.insert('c');
	ms.insert('a');
	string ss(ms.begin(), ms.end());
	cout << ss << endl;

	system("pause");
	return 0;
}