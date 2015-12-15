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
    static bool compareInterval(const Interval& a, const Interval& b){
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() > 0){
            sort(intervals.begin(), intervals.end(), Solution::compareInterval);
            Interval tmp = intervals.at(0);
            for (int i = 1; i < intervals.size(); i++){
                if (intervals.at(i).end < tmp.start || intervals.at(i).start > tmp.end){   // no intervals
                    result.push_back(tmp);
                    tmp = intervals.at(i);
                } else {
                    tmp.start = min(tmp.start, intervals.at(i).start);
                    tmp.end = max(tmp.end, intervals.at(i).end);
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
};
