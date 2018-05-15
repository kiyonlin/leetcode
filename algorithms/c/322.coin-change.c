/*
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (26.61%)
 * Total Accepted:    96.7K
 * Total Submissions: 363.4K
 * Testcase Example:  '[1]\n0'
 *
 * 
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * 
 * 
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * 
 * 
 * 
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 * 
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
inline MIN(int a, int b) { return a < b ? a : b; }

int coinChange(int* coins, int coinsSize, int amount)
{
    int* dp = (int*)malloc(sizeof(int) * (amount + 1));
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        dp[i] = INT_MAX - 1;

    for (int i = 0; i < coinsSize; i++)
        for (int c = coins[i]; c <= amount; c++)
            // c 除去 一枚 coins[i]
            dp[c] = MIN(dp[c], dp[c - coins[i]] + 1);

    return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
}
