#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
所有的递归都可以想成树，像这道题只有'('和')'两种情况的就是比较简单的二叉树
可以类比为二叉树的遍历
其实如果不用map，直接用两个变量left和right来记录'('和')'的个数会更快一些

arrange函数的参数string temp如果写为string& temp会报错
因为temp+'(',会临时生成一个新值，该值默认是const的，然后作为参数传给函数时，函数头接受的却是非const的
去掉&在调用的时候，会将值复制一份，新的值不是const的

这个题其实和有一堆人去买票，有些人有5块，有些人有10块，该如何排列这些人使得10块的人总有钱找零
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	unordered_map<char, int> parenthesis ({{'(', n}, {')', n}});
    	vector<string> result;
    	string temp = "";

    	arrange(result, temp, parenthesis);
    	return result;        
    }

    void arrange(vector<string>& result, string temp, unordered_map<char, int>& parenthesis) {
    	if (parenthesis[')'] == 0) {
    		result.push_back(temp);
    	}

    	if (parenthesis['('] > 0) {
    		--parenthesis['('];
    		arrange(result, temp + '(', parenthesis);
    		++parenthesis['('];
    	}

    	if (parenthesis[')'] > parenthesis['(']) {
    		--parenthesis[')'];
    		arrange(result, temp + ')', parenthesis);
    		++parenthesis[')'];
    	}
    }
};