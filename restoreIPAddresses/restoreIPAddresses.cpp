// Source : https://leetcode.com/problems/restore-ip-addresses/
// Author : weekend27
// Date   : 2015-12-17

/**********************************************************************************
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

**********************************************************************************/

// How to do it:
// ref: http://fisherlei.blogspot.sg/2012/12/leetcode-restore-ip-addresses.html
// 递归的将数字串分成四个部分，每个部分满足0<=p<=255。要注意一些边界case，比如010是没有意思的，“0.10.010.1”。


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> col;
        string ip;
        partitionIP(s, 0, 0, ip, col);
        return col;
    }

    void partitionIP(string s, int startIndex, int partNum, string resultIP, vector<string>& col){
        // max: 3 bits per partition
        if (s.size() - startIndex > (4 - partNum) * 3){
            return;
        }
        // min: 1 bit per partition
        if (s.size() - startIndex < (4 - partNum)){
            return;
        }
        if (startIndex == s.size() && partNum == 4){
            resultIP.resize(resultIP.size() - 1);
            col.push_back(resultIP);
            return;
        }
        int num = 0;
        for (int i = startIndex; i < startIndex + 3; i++){
            num = num * 10 + (s[i] - '0');
            if (num <= 255){
                resultIP += s[i];
                partitionIP(s, i + 1, partNum + 1, resultIP + '.', col);
            }
            if (num == 0){  // 0.0.0.0 valid, but need to avoid 0.1.010.01
                break;
            }
        }
    }
};
