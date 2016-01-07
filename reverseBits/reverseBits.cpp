// Source : https://leetcode.com/problems/reverse-bits/
// Author : weekend27
// Date   : 2016-01-07

/**********************************************************************************

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

**********************************************************************************/

// How to do it:
// ref:http://yucoding.blogspot.com/2015/05/leetcode-questions-reverse-bits.html


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; i++) {
            if (n & mask) {res = res + 1;}
            if (i != 31) res <<= 1;
            mask <<= 1;
        }
        return res;
    }
};
