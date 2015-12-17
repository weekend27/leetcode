// Source : https://leetcode.com/problems/generate-parentheses/
// Author : weekend27
// Date   : 2015-12-17

/**********************************************************************************

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

**********************************************************************************/

// How to do it:
// 典型的递归。一步步构造字符串。当左括号出现次数<n时，就可以放置新的左括号。当右括号出现次数小于左括号出现次数时，就可以放置新的右括号。


class Solution {
public:
    void combinationPar(vector<string>& result, string& sample, int deep, int n, int leftNum, int rightNum){
        if (deep == 2*n){
            result.push_back(sample);
            return;
        }
        if (leftNum < n){
            sample.push_back('(');
            combinationPar(result, sample, deep+1, n, leftNum+1, rightNum);
            sample.resize(sample.size()-1);
        }
        if (rightNum < leftNum){
            sample.push_back(')');
            combinationPar(result, sample, deep+1, n, leftNum, rightNum+1);
            sample.resize(sample.size()-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string sample;
        if (n != 0){
            combinationPar(result, sample, 0, n, 0, 0);
        }
        return result;
    }
};
