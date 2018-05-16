/*
 * [464] Can I Win
 *
 * https://leetcode.com/problems/can-i-win/description/
 *
 * algorithms
 * Medium (25.29%)
 * Total Accepted:    21.2K
 * Total Submissions: 83.7K
 * Testcase Example:  '10\n11'
 *
 * In the "100 game," two players take turns adding, to a running total, any
 * integer from 1..10. The player who first causes the running total to reach
 * or exceed 100 wins. 
 * 
 * What if we change the game so that players cannot re-use integers? 
 * 
 * For example, two players might take turns drawing from a common pool of
 * numbers of 1..15 without replacement until they reach a total >= 100.
 * 
 * Given an integer maxChoosableInteger and another integer desiredTotal,
 * determine if the first player to move can force a win, assuming both players
 * play optimally. 
 * 
 * You can always assume that maxChoosableInteger will not be larger than 20
 * and desiredTotal will not be larger than 300.
 * 
 * 
 * Example
 * 
 * Input:
 * maxChoosableInteger = 10
 * desiredTotal = 11
 * 
 * Output:
 * false
 * 
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers
 * from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >=
 * desiredTotal.
 * Same with other integers chosen by the first player, the second player will
 * always win.
 * 
 * 
 */
char cache[1 << 20 + 1];

bool canWin(int max, int target, unsigned int pool, int score, bool player1Turn);

bool canIWin(int maxChoosableInteger, int desiredTotal)
{
    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
        return false;

    // Init pool as bit map with "1"s on the right marking the numbers not taken
    unsigned int pool = (1 << maxChoosableInteger) - 1;

    // Init cache as -1 (all "1" bits)
    memset(cache, -1, sizeof(cache));

    return canWin(maxChoosableInteger, desiredTotal, pool, 0, true);
}

bool canWin(int max, int target, unsigned int pool, int score, bool player1Turn)
{
    if (cache[pool] != -1)
        return cache[pool];

    for (int i = max; i >= 1; i--)
        // If number not taken yet
        if (pool & (1 << (i - 1)))
            if (score + i >= target || canWin(max, target, pool ^ (1 << (i - 1)), score + i, !player1Turn) == player1Turn)
                return cache[pool] = player1Turn;

    return cache[pool] = !player1Turn;
}
