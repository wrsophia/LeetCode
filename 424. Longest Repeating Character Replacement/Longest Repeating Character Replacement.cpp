#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//ά��һ������

class Solution {
public:
	int characterReplacement(string s, int k) {
		int start = 0, end = 0, maxCount = 0, maxLen = 0;
		int n = s.length();
		unordered_map<char, int> hash;
		for (; end < n; ++end) {
			++hash[s[end]];
			maxCount = max(maxCount, hash[s[end]]);
			if (end - start - maxCount + 1 > k) {        //if����ﲻ����maxCount����ʡ������whileѭ��	
				--hash[s[start]];				         //һ��Ϊʹstart++��ѭ������һ��Ϊ��ȷ�е�maxCount��ѭ��
				++start;                			     //end��startͬʱ���ƣ��������ڶ�̬�滮�еı��浱ǰ���ֵ
			}                                            //ֱ�������˸����maxCount���ſ���ʹ��end���ƣ�����maxLen
			maxLen = end - start + 1;
		}
		return maxLen;
	}
};