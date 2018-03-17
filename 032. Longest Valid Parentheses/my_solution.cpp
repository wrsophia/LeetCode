#include <iostream>
#include <vector>
using namespace std;




class Solution {
public:
    int longestValidParentheses(string s) {
    	int n = s.length();
    	vector<pair<int, int> > parentheses_num(n);
    	int max = 0;

    	for (int i = 0; i < n; ++i) {
    		for (int j = i; j < n; ++j) {
    			if (s[j] == '(') {
    				++ parentheses_num[i].first;
    			} else {
    				++ parentheses_num[i].second;
    			}

    			int first = parentheses_num[i].first;
    			int second = parentheses_num[i].second;

    			if (first < second) {
    				break;
    			}

    			if (first == second && first > max) {
    				max = first;
    			}
    		}
    		
    	}

        return max << 1;
    }
};