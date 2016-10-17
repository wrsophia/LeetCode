#include <iostream>
#include <cstdlib>
using namespace std;

//�����λ��11�ͼ�1�������λ��01�ͼ�1
//3��0x7fff���������

class Solution {
public:
	int integerReplacement(int n) {
		if (n == INT_MAX) {   //special case
			return 32;        //��Ϊ0x8000����λ��ʱ�����Է���λ1����ģ�����ѭ����Զ�����������ʱ����
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