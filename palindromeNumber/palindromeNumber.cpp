// Source : https://leetcode.com/problems/palindrome-number/
// Author : weekend27
// Date   : 2015-12-25

/**********************************************************************************

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

**********************************************************************************/

// How to do it:
// 不断地取第一位和最后一位（10进制下）进行比较，相等则取第二位和倒数第二位，直到完成比较或者中途找到了不一致的位。


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        int div = 1;
        while (x/div >= 10){
            div *= 10;
        }
        while (x > 0){
            int l = x / div;
            int r = x % 10;
            if (l != r){
                return false;
            }
            x = x % div / 10;
            div /= 100;
        }
        return true;
    }
};
