// Source : https://leetcode.com/problems/sliding-window-maximum/
// Author : weekend27
// Date   : 2016-01-15

/**********************************************************************************

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Hint:

How about using a data structure such as deque (double-ended queue)?

**********************************************************************************/

// How to do it:
// use a deque to store temp max

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> max;
        for (int i = 0; i < nums.size(); ++i) {
            while (!max.empty() && nums[i] > max.back()) {
                max.pop_back();
            }
            max.push_back(nums[i]);
            if (i >= k - 1) {
                ret.push_back(max.front());
                if (nums[i - k + 1] == max.front()) {
                    max.pop_front();
                }
            }
        }
        return ret;
    }
};
