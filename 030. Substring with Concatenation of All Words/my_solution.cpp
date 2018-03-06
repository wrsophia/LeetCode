#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> res;
    	if (words.size() == 0) {
    		return res;
    	}

        int N = s.length();
        int n = words.size();
        int M = words[0].length();
        if (N < M * n) {
        	return res;
        }

        unordered_map<string, int> word_idx;
        int dumplicate = 0;
        for (int i = 0; i < n; ++i) {
        	if (word_idx.find(words[i]) != word_idx.end()) {
        		++dumplicate;
        		continue;
        	}
        	word_idx[words[i]] = i - dumplicate;
        }

		int size = N - M + 1;
        vector<int> str_mapping(size, -1);
        for (int i = 0; i < size; ++i) {
        	if (word_idx.find(s.substr(i, M)) != word_idx.end()) {
        		str_mapping[i] = word_idx[s.substr(i, M)];
        	}
        }

        int left = 0;
        unordered_set<int> check_exist;
        while (left <= (N - M * n)) {
        	while (str_mapping[left] == -1) {
        		++left;
        		if (left > (N - M * n)) {
        			return res;
        		}
        	}

        	check_exist.insert(str_mapping[left]);
        	int right = left + M;
        	for (int i = 1; i < n; ++i) {
        		if (str_mapping[right] == -1 || check_exist.count(str_mapping[right] == 1)) {
        			break;
        		}
        		check_exist.insert(str_mapping[right]);
        		right += M;
        	}

        	if (check_exist.size() == n) {
        		res.push_back(left);
        	}

        	++left;
        	check_exist.clear();
        }  
        return res;
    }
};