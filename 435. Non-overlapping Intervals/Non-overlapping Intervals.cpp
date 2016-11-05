#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

/*
����ʱ��endС��������ǰ�棬Ϊ�˸�����������ռ䡣
end��ͬʱstart�����ǰ�棬����С����
��Ϊ���ܻ����һ���ر𳤵����䣬�����˺ü���С���䣬����ɾ����ʱ���ɾ�������Ǹ�������
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