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
// ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-insert-interval.html

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
         vector<Interval> res;
         bool isInsert = false;
         for (int i = 0; i < intervals.size(); ++i) {
             // already insert newInterval
             if (isInsert) {
                 res.push_back(intervals[i]);
                 continue;
             }

             // insert newInterval before current interval
             if (newInterval.end < intervals[i].start) {
                 res.push_back(newInterval);
                 res.push_back(intervals[i]);
                 isInsert = true;
                 continue;
             }

             // combine newInterval with current interval
             if (newInterval.start <= intervals[i].end && intervals[i].start <= newInterval.end) {
                 newInterval.start = min(newInterval.start, intervals[i].start);
                 newInterval.end = max(newInterval.end, intervals[i].end);
                 continue;
             }

             // newInterval after current interval
             res.push_back(intervals[i]);
         }

         if (!isInsert) res.push_back(newInterval);
         return res;
     }
 };
