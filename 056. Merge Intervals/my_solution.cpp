/**
 * 把各区间排序，按权重 start > end 来排
 */


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n < 2) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;

        int first = 0, second = 1;
        int start = intervals[first].start, end = intervals[first].end;
        while (second < n) {
            if (end >= intervals[second].start) {
                end = end > intervals[second].end ? end : intervals[second].end;
                ++second;
            } else {
                res.push_back(Interval(start, end));

                first = second;
                ++second;
                start = intervals[first].start;
                end = intervals[first].end;
            }
        }

        res.push_back(Interval(start, end));
        return res;
    }

    static bool compare(Interval i1, Interval i2) {
        if (i1.start == i2.start) {
            return i1.end < i2.end;
        } else {
            return i1.start < i2.start;
        }
    }
};
