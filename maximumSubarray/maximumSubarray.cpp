// Source : https://leetcode.com/problems/maximum-subarray/
// Author : weekend27
// Date   : 2015-12-20

/**********************************************************************************

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

**********************************************************************************/

// How to do it:
// divide and conquer
/*
subarray A[i,..j] is
(1) Entirely in A[low,mid-1]
(2) Entirely in A[mid+1,high]
(3) Across mid
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxV = INT_MIN;
        return maxArray(nums, 0, n-1, maxV);
    }

    int maxArray(vector<int>& nums, int left, int right, int& maxV){
        if (left > right){
            return INT_MIN;
        }

        int mid = left + (right - left) / 2;
        int lmax = maxArray(nums, left, mid-1, maxV);
        int rmax = maxArray(nums, mid+1, right, maxV);
        maxV = max(lmax, maxV);
        maxV = max(rmax, maxV);

        int lsum = 0;
        int mlmax = 0;
        for (int i = mid-1; i >= left; i--){
            lsum += nums[i];
            if (lsum > mlmax){
                mlmax = lsum;
            }
        }

        int rsum = 0;
        int mrmax = 0;
        for (int i = mid+1; i <= right; i++){
            rsum += nums[i];
            if (rsum > mrmax){
                mrmax = rsum;
            }
        }

        maxV = max(maxV, mlmax + mrmax + nums[mid]);
        return maxV;
    }
};
