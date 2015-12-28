// Source : https://leetcode.com/problems/number-of-1-bits/
// Author : weekend27
// Date   : 2015-12-28

/**********************************************************************************

Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

**********************************************************************************/

// How to do it:
// &

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for (int i = 1; i < 33; i++){
            if (getOne(n, i) == true){
                cnt++;
            }
        }
        return cnt;
    }

    bool getOne(uint32_t n, int i){
        return (n & (1 << i)) != 0;
    }
};
