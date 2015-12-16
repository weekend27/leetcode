// Source : https://leetcode.com/problems/count-and-say/
// Author : weekend27
// Date   : 2015-12-16

/**********************************************************************************

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

**********************************************************************************/

// How to do it:
// string-operation. The only trick thing is Line32. seq[seq.size()] always '\0'. It will help to save an "if" statement.


class Solution {
public:
    string countAndSay(int n) {
        string seq = "1";
        int it = 1;
        while(it < n){
            stringstream newSeq;
            char last = seq[0];
            int cnt = 0;
            for (int i = 0; i <= seq.size(); i++){
                if (seq[i] == last){
                    cnt++;
                    continue;
                } else {
                    newSeq << cnt << last;
                    last = seq[i];
                    cnt = 1;
                }
            }
            seq = newSeq.str();
            it++;
        }
        return seq;
    }
};
