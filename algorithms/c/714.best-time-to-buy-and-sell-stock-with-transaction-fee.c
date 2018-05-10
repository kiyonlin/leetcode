/*
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (46.00%)
 * Total Accepted:    16.1K
 * Total Submissions: 35K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * Your are given an array of integers prices, for which the i-th element is
 * the price of a given stock on day i; and a non-negative integer fee
 * representing a transaction fee.
 * You may complete as many transactions as you like, but you need to pay the
 * transaction fee for each transaction.  You may not buy more than 1 share of
 * a stock at a time (ie. you must sell the stock share before you buy again.)
 * Return the maximum profit you can make.
 * 
 * Example 1:
 * 
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * Buying at prices[0] = 1Selling at prices[3] = 8Buying at prices[4] =
 * 4Selling at prices[5] = 9The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) =
 * 8.
 * 
 * 
 * 
 * Note:
 * 0 < prices.length .
 * 0 < prices[i] < 50000.
 * 0 .
 * 
 */

// 每天操作可以为 买 卖 持有。持有不改变利润，忽略不计。

// 对于第i天，有:
// buy[i]: 第i天的最大利润，且最后的操作是买;
// sell[i]: 第i天的最大利润，且最后的操作是卖;
// 最后的操作可以发生在第i天或之前。
// 假如想获得最大利润，那么最后的操作一定是卖。

// 状态转移方程为:

// buy[i] = max(buy[i-1], sell[i-1] - prices[i] - fee)
// sell[i] = max(sell[i-1], buy[i-1] + prices[i])
// 同时 (buy[i], sell[i]) 基于前一个状态 (buy[i-1], sell[i-1]), 所以可以得出 O(1) 的方案
inline max(int a, int b) { return a > b ? a : b; }
int maxProfit(int* prices, int pricesSize, int fee)
{
    int buy = INT_MIN, sell = 0;
    for (int i = 0; i < pricesSize; i++) {
        int lastBuy = buy;
        buy = max(buy, sell - prices[i] - fee);
        sell = max(sell, lastBuy + prices[i]);
    }

    return sell;
}
