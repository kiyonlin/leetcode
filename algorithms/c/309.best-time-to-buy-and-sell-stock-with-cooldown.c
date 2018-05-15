/*
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (42.13%)
 * Total Accepted:    61.7K
 * Total Submissions: 146.4K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like
 * (ie, buy one and sell one share of the stock multiple times) with the
 * following restrictions:
 * 
 * 
 * ⁠   You may not engage in multiple transactions at the same time (ie, you
 * must sell the stock before you buy again).
 * ⁠   After you sell your stock, you cannot buy stock on next day. (ie,
 * cooldown 1 day)
 * 
 * 
 * Example:
 * 
 * prices = [1, 2, 3, 0, 2]
 * maxProfit = 3
 * transactions = [buy, sell, cooldown, buy, sell]
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
inline int MAX(int a, int b) { return a > b ? a : b; }

int maxProfit(int* prices, int pricesSize)
{
    if (pricesSize < 2)
        return 0;
    // day i-1 actions
    int has1_do_nothing = -prices[0],
        has1_sell = 0,
        has0_buy = -prices[0],
        has0_do_nothing = 0;

    for (int i = 1; i < pricesSize; i++) {
        // day i actions based on day i-1
        has1_do_nothing = MAX(has1_do_nothing, has0_buy);
        has0_buy = has0_do_nothing - prices[i];
        has0_do_nothing = MAX(has0_do_nothing, has1_sell);
        has1_sell = has1_do_nothing + prices[i];
    }

    return MAX(has1_sell, has0_do_nothing);
}
