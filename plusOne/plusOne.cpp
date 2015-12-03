// Source : https://leetcode.com/problems/plus-one/
// Author : weekend27
// Date   : 2015-12-02

/**********************************************************************************

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

**********************************************************************************/

// How to do it:
// from the rbegin to the rend, ensure iterator and carry through % and / 

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        add(digits, 1);
        return digits;
    }
private:
    void add(vector<int>& num, int digit){
        int c = digit; // carry
        for(auto it = num.rbegin(); it != num.rend(); it++){
            *it += c;
            c = *it / 10
            *it %= 10;
        }
        if (c != 0)
            num.insert(num.begin(), 1);
    }
};
