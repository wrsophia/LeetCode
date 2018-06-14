/**
 * 思路很简单，因为intervals没有重叠，于是只要找到正确的位置插入进去即可
 * 但是如果先插入再删除或是先删除再插入都太费时间了，于是我们从该删除的下一个元素开始删除，再把这个元素改成要插入的元素
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        // find insert position
        vector<Interval>::iterator insert = intervals.begin();
        while (insert < intervals.end() && insert->end < newInterval.start) {
            ++insert;
        }

        if (insert == intervals.end() || newInterval.end < insert->start) {      // no overlap
            intervals.insert(insert, newInterval);
        } else {
            int start = min(insert->start, newInterval.start);
            vector<Interval>::iterator erase = insert;   // find erase()'s second parameter

            while (erase < intervals.end() && erase->end <= newInterval.end) {
                ++erase;
            }
            int end = newInterval.end;
            if (erase < intervals.end() && erase->start <= newInterval.end) {
                end = erase->end;
                ++erase;
            }

            intervals.erase(insert + 1, erase);
            insert->start = start;
            insert->end = end;
        }

        return intervals;
    }
};
