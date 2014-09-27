/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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
    void qsort(vector<Interval> &intervals, int begin, int end){
        if(end - begin <= 1) return;
        int p = begin + 1, i = p;
        while(i < end){
            if(intervals[i].start < intervals[begin].start){
                Interval t = intervals[p]; intervals[p] = intervals[i]; intervals[i] = t;
                p++;
            }
            i++;
        }
        Interval t = intervals[begin]; intervals[begin] = intervals[p-1]; intervals[p-1] = t;
        qsort(intervals, begin, p-1);
        qsort(intervals, p, end);
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        qsort(intervals, 0, intervals.size());
        int i = 0;
        while(i < intervals.size()){
            while(i+1 < intervals.size() && intervals[i].end < intervals[i+1].start) i++;
            if(i+1 < intervals.size()) {
                int j = i + 1;
                while(j < intervals.size() && intervals[i].end >= intervals[j].start) {
                    intervals[i].end = max(intervals[i].end, intervals[j].end);
                    j++;
                }
                intervals.erase(intervals.begin() + i + 1, intervals.begin() + j);
            }
            if(i+1 == intervals.size()) break;
        }
        return intervals;
    }
};
