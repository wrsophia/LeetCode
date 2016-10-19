#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//优先队列，还是topK的思想

class Solution {
public:
	struct compare{
		const bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
			return (a.first + a.second) < (b.first + b.second);
		}
	};
	vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
		int n1 = min(k, (int)nums1.size()), n2 = min(k, (int)nums2.size());
		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < n2; ++j) {
				if (pq.size() < k) {
					pq.push(make_pair(nums1[i], nums2[j]));
				}
				else {
					if (pq.top().first + pq.top().second > nums1[i] + nums2[j]) {
						pq.pop();
						pq.push(make_pair(nums1[i], nums2[j]));
					}
				}
			}
		}
		vector<pair<int, int> > ans;
		while (!pq.empty()) {
			ans.push_back(pq.top());
			pq.pop();
		}
		return ans;
	}
};