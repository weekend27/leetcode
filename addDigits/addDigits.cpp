// Source : https://leetcode.com/problems/add-digits/
// Author : weekend27
// Date   : 2015-12-25

/**********************************************************************************

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

A naive implementation of the above process is trivial. Could you come up with other methods?

**********************************************************************************/

// How to do it:
// ref: http://www.cnblogs.com/maples7/p/4734300.html

class Solution {
public:
    int addDigits(int num) {
        if (num == 0){
            return 0;
        }
        else{
            return (num - 1) % 9 + 1;
        }
    }
};
