#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;


//���߶Ƚ����������߶���ͬ��.second��������Ȼ��ŵ�list���ڽ��в���


class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), cmp);
		list<pair<int, int>> order;
		order.assign(people.begin(), people.end());
		auto it = order.begin();
		while (it != order.end()) {
			auto head = order.begin();
			int cnt = 0;
			while (cnt < it->second) {
				++head, ++cnt;
			}
			if (head != it) {
				pair<int, int> node = *it;
				it = order.erase(it);
				order.insert(head, node);
			}
			else
				++it;
		}
		people.assign(order.begin(), order.end());
		return people;
	}
	static bool cmp(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	}
};