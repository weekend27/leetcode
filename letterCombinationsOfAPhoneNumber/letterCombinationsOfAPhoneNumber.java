// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : weekend27
// Date   : 2016-04-27

/**********************************************************************************

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

**********************************************************************************/

// How to do it:
// ref: https://leetcode.com/discuss/99739/leebook-%E4%B8%A4%E7%A7%8D%E6%80%9D%E8%B7%AF%E8%A7%A3%E5%86%B3%E7%BB%84%E5%90%88%E9%97%AE%E9%A2%98%EF%BC%88%E9%99%84%E8%A7%A3%E9%87%8A%EF%BC%8C%E5%9B%BE%E7%A4%BA%EF%BC%8C%E4%BB%A3%E7%A0%81%EF%BC%89
/*
这道题的含义在于枚举所有可能的组合方式。
它的难点在于：你不知道输入是什么，所以无法确定组合的长度，组合的个数，也就没有办法去确定循环的层数。
有两个思路：递归和队列。

思路1：递归
递归一般是解决一些整体不好求的问题。它通过把大问题划小，然后找到一种特定的规律，然后求解。

递归的思路我们很好理解，我们没办法确定整体，我可以先从具体例子入手。

假定有个数字串“23456”

假定除了数字'2'外，后一串数字的组合我已经求出来了，那我只要把‘2'所代表的'abc'加到他们每一个的前面就好。所以现在只用求数字串"3456"
假定'3'之后一串数字的组合我已经求出来了，那我只要把‘3'所代表的'def'加到他们每一个的前面就好。所以现在只用求数字串"456" ……
一直这样推下去，直到发现6'后面是空的了，那返回它代表的每个字母就好了。

*************************************************************

思路2：队列
队列的思路也不算太难理解。如果递归算纵向求解的话，队列就是横向求解。每加入一个新的数字的时候，就把当前队列的元素全都扩充一遍。使得队列不仅在长度上，也在宽度上增加了。这就像一个装配流水线。半成品每流过一个工人，工人就把之前的产品拿出来，往上安装一个零件，然后放到传送带上，让它继续传到下个工人那。

（1）一共需要的工人数，就是数字串长度，它决定了产品需要经过几道加工。
for(int i = 0;i < digits.length(); i++)
{
}

（2）然后我们看目前有多少个不同的半成品需要加工。
int pos = digits.charAt(i) - '0';
int size = result.size();
for(int j = 0;j < size;j++)
{
}

（3）然后就开始加工了，我们获取每个数字对应的字符串长度，这就是工人需要加工的零件个数。这里加工是把每个半成品拿出来，复制多份，然后按上新的零件 ```
String tmp = result.remove();
for(int k = 0;k < map[pos].length();k++)
  result.add(tmp+map[pos].charAt(k));

*/


// 递归解法
public class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (digits == null || digits.length() == 0) return result;

        // map array
        String[] digitletters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.add("");

        for (int i = 0; i < digits.length(); i++) {
            int digit = digits.charAt(i) - '0';
            result = combine(result, digitletters[digit]);
        }

        return result;
    }

    public static List<String> combine(List<String> prev, String digit) {
        List<String> result = new ArrayList<>();
        
        for (int i = 0; i < digit.length(); ++i)
            for (String x : prev)
                result.add(x + digit.charAt(i));

        return result;
    }
}
