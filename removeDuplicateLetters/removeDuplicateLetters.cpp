// Source : https://leetcode.com/problems/remove-duplicate-letters/
// Author : weekend27
// Date   : 2015-12-19

/**********************************************************************************

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

**********************************************************************************/

// How to do it:
// greedy algorithm
// use a stack to store the current optimal solution,
// if the new element is smaller than the top of stack
// and the top element is not the last time appear
// and the new element is not existed in the stack,
// then pop, 
// until the new element can push into stack or make sure that it can not be inserted.



class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "";
        stack<char> stack;
        vector<bool> exist(26);
        vector<int> sum(26), cnt(26);

        for (int i = 0; i < s.size(); i++){
            sum[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); i++){
            while (!stack.empty() && s[i] <= stack.top() && cnt[stack.top() - 'a'] != sum[stack.top() - 'a'] && !exist[s[i] - 'a']){
                exist[stack.top() - 'a'] = false;
                stack.pop();
            }
            if (!exist[s[i] - 'a']){
                exist[s[i] - 'a'] = true;
                stack.push(s[i]);
            }
            cnt[s[i] - 'a']++;
        }

        while (!stack.empty()){
            res += stack.top();
            stack.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
