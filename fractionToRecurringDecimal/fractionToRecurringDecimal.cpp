// Source : https://leetcode.com/problems/fraction-to-recurring-decimal/
// Author : weekend27
// Date   : 2015-12-22

/**********************************************************************************

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

**********************************************************************************/

// How to do it:
// ref: http://www.meetqun.com/thread-3328-1-1.html
/*
分析： 这题数据很牛，但是不极端。 我的意思是：
（1）牛的意思是： 分子，分母出现了正负数，以及负数最小值，所以如果都变成正数，会溢出，需要long long
（2）不极端的意思是： 循环节不会太长。因为确实可以构造出寻环节是接近分母那么长的数。 例如 1/1999999943 有兴趣的可以试试，无论用什么办法存余数，空间是不够的，就算空间够，输出那么多位时间也是不够的。
思路： 就是模拟我们手算做除法的过程。我们就是用分子除以分母，然后保存前一次的余数，每次把余数＊10，再除以分母，保存商，再保存余数……如此往复。当余数为0的时候，就除尽了。当余数在之前出现的时候，我们就找到了一个寻环节。所以我们需要一个结构保存这个余数在什么时候出现。余数两次出现的之间部分的商，就是一个寻环节。
时间复杂度： 显然这个时间复杂度取决于寻环节的长度……寻环节的长度，根据抽屉原理，余数最多有分母那么多种，所以循环节的长度可以达到分母。所以时间复杂度和空间复杂度都是O(分母），这还是很大的。这也决定了，我们不能一次性开一个分母那么大的数组。因为存余数出现的最直接的办法是用一个数组have[0..分母 － 1]来记录该余数什么时候出现的，起初都设置为－1来表示没出现过，但这太大了。就算寻环节没那么长，我们也需要那么长的数组。所以这个题记录余数出现位置的时候，需要用map或者hash，我就用c++的unordered_map了。
其余就是输出格式上的处理了。
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        ostringstream out;
        long long Numerator = numerator, Denominator = denominator;
        if (Denominator < 0){
            Denominator = -Denominator;
            Numerator = -Numerator;
        }

        if (Numerator < 0){
            Numerator = -Numerator;
            out << "-";
        }

        out << (Numerator / Denominator);
        long long remainder = Numerator % Denominator;
        if (remainder == 0){
            return out.str();
        }

        out << ".";
        vector<int> temp;
        unordered_map<int, int> have;
        for (int i = 0; remainder && (have.find(remainder) == have.end()); ++i){
            have[remainder] = i;
            remainder *= 10;
            temp.push_back(remainder / Denominator);
            remainder %= Denominator;
        }
        if (remainder){
            for (int j = 0; j < have[remainder]; ++j){
                out << temp[j];
            }
            out << "(";
            for (int j = have[remainder]; j < temp.size(); ++j){
                out << temp[j];
            }
            out << ")";
        }
        else {
            for (int j = 0; j < temp.size(); ++j){
                out << temp[j];
            }
        }

        return out.str();
    }
};
