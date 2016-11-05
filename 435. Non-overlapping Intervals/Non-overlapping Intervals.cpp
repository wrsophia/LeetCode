#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

/*
排序时把end小的优先排前面，为了给后面留更多空间。
end相同时start大的排前面，留下小区间
因为可能会出现一个特别长的区间，覆盖了好几个小区间，但是删除的时候该删除的是那个长区间
*/

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:

	static bool cmp(Interval a, Interval b) {
		return (a.end < b.end || (a.end == b.end && a.start > b.start));
	}

	int eraseOverlapIntervals(vector<Interval>& intervals) {
		int n = intervals.size();
		if (n <= 1) return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int cnt = 1, end = intervals[0].end;
		for (int i = 1; i < n; ++i) {
			if (intervals[i].start >= end) {
				++cnt;
				end = intervals[i].end;
			}
		}
		return n - cnt;
	}
};