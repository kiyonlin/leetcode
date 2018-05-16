/*
 * [375] Guess Number Higher or Lower II
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
 *
 * algorithms
 * Medium (36.14%)
 * Total Accepted:    31K
 * Total Submissions: 85.7K
 * Testcase Example:  '1'
 *
 * We are playing the Guess Game. The game is as follows: 
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number I picked is
 * higher or lower. 
 * 
 * However, when you guess a particular number x,  and you guess wrong, you pay
 * $x. You win the game when you guess the number I picked.
 * 
 * 
 * Example:
 * 
 * n = 10, I pick 8.
 * 
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 * 
 * Game over. 8 is the number I picked.
 * 
 * You end up paying $5 + $7 + $9 = $21.
 * 
 * 
 * 
 * Given a particular n ≥ 1, find out how much money you need to have to
 * guarantee a win.
 * 
 * Credits:Special thanks to @agave and @StefanPochmann for adding this problem
 * and creating all test cases.
 */

inline int MIN(int a, int b) { return a < b ? a : b; }
inline int MAX(int a, int b) { return a > b ? a : b; }
int minCost(int**, int low, int high);

int getMoneyAmount(int n)
{
    int** dp = (int**)malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i <= n; i++)
        dp[i] = (int*)calloc(n + 1, sizeof(int));

    return minCost(dp, 1, n);
}

int minCost(int** dp, int low, int high)
{
    if (low >= high)
        return 0;
    if (dp[low][high] == 0) {
        int minAmount = INT_MAX;
        for (int guess = low; guess <= high; guess++) {
            // 每次获取至少的花费
            int costOnGuess = guess + MAX(minCost(dp, low, guess - 1), minCost(dp, guess + 1, high));
            // 获取其中最小的
            minAmount = MIN(minAmount, costOnGuess);
        }
        dp[low][high] = minAmount;
    }
    return dp[low][high];
}
