// Source : https://leetcode.com/problems/insert-interval/
// Author : weekend27
// Date   : 2015-12-15

/**********************************************************************************

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

**********************************************************************************/

// How to do it:
// just look at the code

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
        auto it = intervals.begin();
        auto it_head = it;          // head of erase items
        while (it != intervals.end()){
            if (newInterval.end < it->start){
                it = intervals.erase(it_head, it);
                intervals.insert(it, newInterval);
                return intervals;
            } else if (newInterval.start > it->end){
                it++;
                it_head++;
            } else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it++;
            }
        }

        if (it_head != it){
            it = intervals.erase(it_head, it);
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};
