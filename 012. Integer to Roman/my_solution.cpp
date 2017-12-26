#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
其实就看千位、百位、十位、个位是什么数字就好，4和9有点特殊，>5,<9 和 <4 情况类似
*/

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> roman = {
            {1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}
        };

        string res = "";
       
        for (int div = 1000; div > 0; div /=10) {

        	int count = num / div;
        	num -= count * div;

        	if (count == 9 || count == 4) {
        		res += roman[div];
        		res += roman[++count * div];    //这里有点坑啊，必须得分两行写，不然会出现无法识别字符
        		count = 0;
        	} else if (count >= 5) {
        		res += roman[5 * div];
        		count -= 5;
        	}
        	while(count > 0) {
        		res += roman[div];
        		--count;
        	}
        }
        return res;
    }

};