// Source : https://leetcode.com/problems/add-binary/
// Author : weekend27
// Date   : 2015-12-16

/**********************************************************************************

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

**********************************************************************************/

// How to do it:
// reverse a and b, and then plus them one bit by one bit
// note that carry in the end


class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int maxLen = max(a.size(), b.size());
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int carry = 0;
        int num = 2;   // binary
        for (int i = 0; i < maxLen; i++){
            int ai = i < a.size() ? a[i]-'0' : 0;
            int bi = i < b.size() ? b[i]-'0' : 0;
            int val = (ai + bi + carry) % num;
            carry = (ai + bi + carry) / num;
            result.insert(result.begin(), val + '0');
        }
        if (carry == 1){
            result.insert(result.begin(), '1');
        }
        return result;
    }
};
