#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

/*
遇到左括号就入栈，遇到右括号就判断栈顶是否能和右括号对应起来并弹栈
若中途栈空了或者最后栈非空都应返回false
*/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parentheses ({{'(', ')'}, {'[', ']'}, {'{', '}'}});
        stack<char> parentheses_stack;

        for (int i = 0; i < s.length(); ++i) {
        	if (parentheses.find(s[i]) != parentheses.end()) {
        		parentheses_stack.push(s[i]);
        	} else {
        		if (parentheses_stack.empty() || parentheses[parentheses_stack.top()] != s[i]) {
        			return false;
        		}
        		parentheses_stack.pop();
        	}
        }
        return parentheses_stack.empty() ? true : false;
    }
};