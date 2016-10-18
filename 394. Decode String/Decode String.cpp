#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		stack<int> num;
		stack<string> res;
		int cur = 0, len = s.length();
		
		res.push("");  //��ֹ��ͷ����'['������ĸ���ַ���������ȡ��ʱresΪ�ձ���
		while (cur < len) {
			if (isdigit(s[cur])) {
				int cnt = 0;
				while (isdigit(s[cur])) {					
					cnt = cnt * 10 + s[cur] - '0';
					++cur;
				}
				--cur;
				num.push(cnt);
			}
			else if (s[cur] == '[') {
				res.push("");  //������Ž��մ���ǰ��Ĳ��ָ��룬��ô��else����ȡ�õ�ʱ��ͻ��õ�'['֮ǰ���ַ�
			}
			else if (s[cur] == ']') {
				int n = num.top();
				num.pop();
				string tmp = res.top();
				res.pop();
				string s = "";
				for (int i = 0; i < n; ++i) {
					s += tmp;
				}
				tmp = res.top();
				res.pop();
				res.push(tmp + s);
			}
			else {
				string tmp = res.top();
				res.pop();
				res.push(tmp + s[cur]);
			}
			++cur;
		}
		string ans = res.top();
		res.pop();
		return ans;
	}
};

int main() {
	Solution sol;
	string test = "3[a2[c]]";
	cout << sol.decodeString(test) << endl;
	system("pause");
	return 0;
}