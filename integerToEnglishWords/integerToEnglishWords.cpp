// Source : https://leetcode.com/problems/integer-to-english-words/
// Author : weekend27
// Date   : 2015-12-17

/**********************************************************************************

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

**********************************************************************************/

// How to do it:
// ref: http://my.oschina.net/Tsybius2014/blog/516047
// make 3 digits as a processing unit

class Solution {
public:
    string numberToWords(int num) {
        if (num < 0){
            return "";
        }

        if (num == 0){
            return "Zero";
        }

        int segment1 = num / 1000000000;                // billion to one hundred billion
        int segment2 = num % 1000000000 / 1000000;      // million to billion
        int segment3 = num % 1000000 / 1000;            // thousand to million
        int segment4 = num % 1000;                      // zero to thousand

        string result = "";

        if (segment1 > 0){
            result += numToWordsLessThan1000(segment1) + " " + "Billion";
        }
        if (segment2 > 0){
            result += numToWordsLessThan1000(segment2) + " " + "Million";
        }
        if (segment3 > 0){
            result += numToWordsLessThan1000(segment3) + " " + "Thousand";
        }
        if (segment4 > 0){
            result += numToWordsLessThan1000(segment4);
        }

        int i = 0;
        while (result[i] == ' '){
            i++;
        }
        return result.substr(i);
    }

private:
    string numToWordsLessThan1000(int num){
        if (num == 0 || num > 1000){
            return "";
        }

        string result = "";
        if (num >= 100){
            result += numToWordsBase(num / 100) + " " + "Hundred";
        }
        num = num % 100;
        if (num > 20){
            result += numToWordsBase(num / 10 * 10);
            if (num % 10 != 0){
                result += numToWordsBase(num % 10);
            }
        } else if (num > 0){
            result += numToWordsBase(num);
        }

        for (int i = 0; i < result.size(); i++){
            if(result[i] == ' '){
                i++;
            }
        }
        return result;
    }

private:
    string numToWordsBase(int num){
        string result = " ";
        switch(num){
            case 1 : result += "One"; break;
            case 2 : result += "Two"; break;
            case 3 : result += "Three"; break;
            case 4 : result += "Four"; break;
            case 5 : result += "Five"; break;
            case 6 : result += "Six"; break;
            case 7 : result += "Seven"; break;
            case 8 : result += "Eight"; break;
            case 9 : result += "Nine"; break;
            case 10: result += "Ten"; break;
            case 11: result += "Eleven"; break;
            case 12: result += "Twelve"; break;
            case 13: result += "Thirteen"; break;
            case 14: result += "Fourteen"; break;
            case 15: result += "Fifteen"; break;
            case 16: result += "Sixteen"; break;
            case 17: result += "Seventeen"; break;
            case 18: result += "Eighteen"; break;
            case 19: result += "Nineteen"; break;
            case 20: result += "Twenty"; break;
            case 30: result += "Thirty"; break;
            case 40: result += "Forty"; break;
            case 50: result += "Fifty"; break;
            case 60: result += "Sixty"; break;
            case 70: result += "Seventy"; break;
            case 80: result += "Eighty"; break;
            case 90: result += "Ninety"; break;
        }

        return result;
    }
};
