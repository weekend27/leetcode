// Source : https://leetcode.com/problems/reverse-words-in-a-string/
// Author : weekend27
// Date   : 2015-12-18

/**********************************************************************************

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

**********************************************************************************/

// How to do it:
// find words first, then reverse, no tricks

class Solution {
public:
    void reverseWords(string &s) {
        int begin = 0;      // the begin position of a word
        int end = 0;        // the end position of a word
        string temp;
        vector<string> result;
        while (true){
            begin = s.find_first_not_of(' ', begin);    // find the first letter
            if (begin == -1){  // no word
                break;
            }
            end = s.find_first_of(' ', begin);
            if (end == -1){ //there is no space behind the last word
                end = s.length();
            }
            // find the last letter
            temp.assign(s, begin, end - begin);
            result.push_back(temp);
            if (end == s.length() - 1){
                break;
            }
            begin = end;
        }

        string resultStr;
        if (result.size() > 0){
            // reverse
            for (int i = 0; i < result.size() - 1; i++){
                resultStr.append(result[result.size() - 1 - i]);
                resultStr.append(1, ' ');  // append one whitespace
            }
            resultStr.append(result[0]);
        }
        s = resultStr;
    }
};
