// Source : https://leetcode.com/problems/merge-intervals/
// Author : weekend27
// Date   : 2016-03-22

/**********************************************************************************

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/50164/my-c-o-nlogn-solution-580ms
/*
Just copy the input to res and do sorting (in ascending order of start).
Then try to merge the sorted interval: cur is the last processed interval and i is the current to-be-processed interval.
If cur is ahead of i and no overlapping, just copy i to cur+1, and update cur to cur+1, otherwise, merge interval cur and i and move to i+1.
At last, we need to resize res to remove the redundent intervals.
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
         vector<Interval> res(intervals);
 	    int cur, i;
         if (intervals.size() > 1) {
             std::sort(res.begin(), res.end(), [](Interval a, Interval b){return a.start < b.start;});
             for (cur = 0, i = 1; i < intervals.size(); ++i) {
                 if (res[cur].end < res[i].start) res[++cur] = res[i];  // no overlapping, copy to cur+1
                 else res[cur].end = max(res[cur].end, res[i].end);
             }
 	        res.resize(cur+1);    // resize to remove redundant intervals
         }
         return res;
     }
 };
