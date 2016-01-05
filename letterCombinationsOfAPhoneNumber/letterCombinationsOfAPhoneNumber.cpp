// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : weekend27
// Date   : 2016-01-05

/**********************************************************************************

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

**********************************************************************************/

// How to do it:
// ref: http://fisherlei.blogspot.jp/2012/12/leetcode-letter-combinations-of-phone.html


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> trans = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> set;
        string seq;
        if (digits == "") {
            return set;
        }
        generator(trans, digits, 0, seq, set);
        return set;
    }

    void generator(vector<string>& trans, string& digits, int deep, string& result, vector<string>& set) {
        if (deep == digits.size()) {
            set.push_back(result);
            return;
        }

        int curDig = digits[deep] - 48;
        for (int i = 0; i < trans[curDig].size(); i++) {
            result.push_back(trans[curDig][i]);
            generator(trans, digits, deep+1, result, set);
            result.resize(result.size() - 1);
        }
    }
};
