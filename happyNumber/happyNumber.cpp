// Source : https://leetcode.com/problems/happy-number/
// Author : weekend27
// Date   : 2015-12-22

/**********************************************************************************

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

**********************************************************************************/

// How to do it:
// ref: http://yucoding.blogspot.sg/2015/06/leetcode-question-happy-number.html
/*
This problem is not difficult, just be careful with the terminating condition.
In my answer, I use a set to store the previous numbers in each round.
If current number is in this set, then this number cannot be "happy" since there must have an endless loop.
*/

class Solution {
public:
    bool isHappy(int n) {
        int res = 0;
        unordered_set<int> hist;

        while (true){
            if (n == 1){
                return true;
            }

            while (n > 0){
                res += (n%10) * (n%10);
                n /= 10;
            }

            if (hist.find(res) != hist.end()){
                return false;
            }
            else{
                hist.insert(res);
                n = res;
                res = 0;
            }
        }
    }
};
