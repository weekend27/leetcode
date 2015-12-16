// Source : https://leetcode.com/problems/anagrams/
// Author : weekend27
// Date   : 2015-12-16

/**********************************************************************************

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

**********************************************************************************/

// How to do it:
// first sort str[i], then hash map, then print the second element of hash map


class Solution {
public:
    string getCode(string s){
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> results;
        int size = strs.size();
        if(size == 0){
            return results;
        }
        if(size == 1){
            results.push_back(strs);
            return results;
        }

        map<string, vector<string>> head;

        for(int i = 0; i < size; ++i){
            head[getCode(strs[i])].push_back(strs[i]);
        }

        map<string, vector<string> >::iterator itor = head.begin(), end = head.end();

        for(; itor != end; ++itor){
            sort(itor->second.begin(), itor->second.end());
            results.push_back(itor->second);
        }
        return results;
    }
};
