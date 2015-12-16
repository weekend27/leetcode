// Source : https://leetcode.com/problems/longest-common-prefix/
// Author : weekend27
// Date   : 2015-12-16

/**********************************************************************************

Write a function to find the longest common prefix string amongst an array of strings.

**********************************************************************************/

// How to do it:
// traverse the string array, use the current prefix to map the next string in order to produce a new prefix


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cmp;
        if (strs.size() == 0){
            return cmp;
        }
        cmp = strs[0];
        for (int i = 0; i < strs.size(); i++){
            string prefix;
            int k = 0;
            while (k < cmp.size() && k < strs[i].size()){
                if (cmp[k] != strs[i][k]){
                    break;
                }
                prefix.append(1, cmp[k]);
                k++;
            }
            cmp.clear();
            cmp.append(prefix.c_str());
        }
        return cmp;
    }
};
