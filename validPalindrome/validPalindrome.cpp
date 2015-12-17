// Source : https://leetcode.com/problems/valid-palindrome/
// Author : weekend27
// Date   : 2015-12-17

/**********************************************************************************

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

**********************************************************************************/

// How to do it:
// two pointers, meet at the middle pos

class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.size() - 1;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (begin < end){
            while (begin < end && !isAlpha(s[begin])) begin++;  // filter non-alpha char
            while (begin < end && !isAlpha(s[end])) end--;  // filter non-alpha char
            if (s[begin] != s[end]){
                break;
            }
            begin++;
            end--;
        }
        if (begin >= end){
            return true;
        } else {
            return false;
        }
    }

    bool isAlpha(char c){
        if (c >= 'a' && c <= 'z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
};
