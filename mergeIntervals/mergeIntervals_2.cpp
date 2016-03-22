// Source : https://leetcode.com/problems/merge-intervals/
// Author : weekend27
// Date   : 2015-12-15

/**********************************************************************************

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

**********************************************************************************/

// How to do it:
// first sort the start, then check the corner


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
         if (intervals.empty()) return vector<Interval>{};
         vector<Interval> res;
         sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
         res.push_back(intervals[0]);
         for (int i = 0; i < intervals.size(); ++i) {
             if (res.back().end < intervals[i].start) {
                 res.push_back(intervals[i]);
             }
             else {
                 res.back().end = max(res.back().end, intervals[i].end);
             }
         }

         return res;
     }
 };
