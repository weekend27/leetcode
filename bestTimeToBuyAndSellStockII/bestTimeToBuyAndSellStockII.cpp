// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : weekend27
// Date   : 2015-12-28

/**********************************************************************************

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

**********************************************************************************/

// How to do it:
// look at the code


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] - prices[i-1] > 0){
                p += prices[i] - prices[i-1];
            }
        }
        return p;
    }
};
