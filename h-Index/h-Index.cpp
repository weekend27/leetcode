// Source : https://leetcode.com/problems/h-index/
// Author : weekend27
// Date   : 2015-12-16

/**********************************************************************************

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

**********************************************************************************/

// How to do it:
// binary search



class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int len = citations.size();
        int start = 0;
        int end = len;

        while(start < end)
        {
            int mid = start + (end - start) / 2;

            if(len - mid <= citations[mid])
            {
                if(mid == 0 || len - mid + 1 > citations[mid - 1])
                {
                    return (min((int)len - mid,citations[mid]));
                }

                end = mid;
            }

            if(len - mid > citations[mid])
            {
                start = mid + 1;
            }
        }

        return 0;
    }
};
