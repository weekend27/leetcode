// Source : https://leetcode.com/problems/largest-number/
// Author : weekend27
// Date   : 2015-12-15

/**********************************************************************************

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

**********************************************************************************/

// How to do it:
// special sort
// 贪心算法
// ref：http://www.w2bc.com/Article/19411

class Solution {
public:
    static bool compare(const string &a, const string &b){
        string ab = a + b;
        string ba = b + a;
        return ab > ba;
    }
    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        vector<string> vec;
        if (len == 0){
            return NULL;
        }

        int zeroCount = 0;
        for (int i = 0; i < len; i++){
            if (nums[i] == 0){
                zeroCount++;
            }
            char str[len-1];
            sprintf(str, "%d", nums[i]);
            vec.push_back(str);
        }

        if (zeroCount == len){
            return "0";
        }

        if (len == 1){
            return vec[0];
        }

        sort(vec.begin(), vec.end(), compare);

        string result;
        for (int i = 0; i < len; i++){
            result += vec[i];
        }
        return result;
    }
};
