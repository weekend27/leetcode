// Source : https://leetcode.com/problems/pascals-triangle-ii/
// Author : weekend27
// Date   : 2015-12-02

/**********************************************************************************

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

**********************************************************************************/

// How to do it:
// two pointers
// from the end to the start, fresh your vector
// space O(k)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex + 1);

        vec[0] = 1;
        for (int i = 1; i <= rowIndex; i++)
            for (int j = i; j >= 0; j--)
                if (j == i)
                    vec[j] = vec[j-1];
                else if (j == 0)
                    vec[j] = vec[j];
                else
                    vec[j] = vec[j-1] + vec[j];

        return vec;
    }
};
