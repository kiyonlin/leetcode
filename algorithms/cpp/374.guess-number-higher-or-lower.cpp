/*
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (36.96%)
 * Total Accepted:    75.4K
 * Total Submissions: 204K
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows: 
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number is higher or
 * lower.
 * 
 * You call a pre-defined API guess(int num) which returns 3 possible results
 * (-1, 1, or 0):
 * 
 * -1 : My number is lower
 * ⁠1 : My number is higher
 * ⁠0 : Congrats! You got it!
 * 
 * 
 * Example:
 * 
 * n = 10, I pick 6.
 * 
 * Return 6.
 * 
 * 
 */
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    long helper(long low, long high)
    {
        if (low == high)
            return low;
        long mid = (low + high) / 2;

        if (guess(mid) == 0)
            return mid;
        else if (guess(mid) < 0)
            return helper(1, mid - 1);
        else
            return helper(mid + 1, high);
    }
    int guessNumber(int n)
    {
        return helper(1, n);
    }
};
