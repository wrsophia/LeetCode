#include<iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string> > tickets) {
		unordered_map<string, multiset<string> > hash;
		for (auto i : tickets) {
			hash[i.first].insert(i.second);
		}
		vector<string> ans;
		stack<string> s;
		s.push("JFK");
		while (!s.empty()) {
			string tmp = s.top();
			if (hash[tmp].empty()) {
				ans.push_back(tmp);
				s.pop();
			}
			else {
				s.push(*hash[tmp].begin());
				hash[tmp].erase(hash[tmp].begin());
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};


int main() {
	unordered_map<string, multiset<string> > hash;
	hash["abc"].insert("hello");
	hash["abc"].erase(hash["abc"].begin());
	cout << boolalpha << hash["abc"].empty() << hash["abc"].size() << endl;
	cout << boolalpha << hash["ab"].empty() << hash["ab"].size() << endl;
	system("pause");
	return 0;
}