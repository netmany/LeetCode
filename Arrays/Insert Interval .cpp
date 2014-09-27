/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.size() == 0) {
            intervals.push_back(newInterval); 
            return intervals;
        }
        if(intervals[0].start > newInterval.end) { 
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if(intervals[intervals.size() - 1].end < newInterval.start) { 
            intervals.push_back(newInterval); 
            return intervals;
        }
        int i = 0, b, e;
        while(i < intervals.size() && intervals[i].end < newInterval.start) i++;
        b = i;
        i = intervals.size() - 1;
        while(i >= 0 && intervals[i].start > newInterval.end) i--;
        e = i;
        
        if(b > e) {
            intervals.insert(intervals.begin() + b, newInterval);
        } else {
            intervals[b].start = min(intervals[b].start, newInterval.start);
            intervals[b].end = max(intervals[e].end, newInterval.end);
            if(b < e) intervals.erase(intervals.begin() + b + 1, intervals.begin() + e + 1);
        }
        return intervals;
    }
};
