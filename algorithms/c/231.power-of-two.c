/*
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (40.80%)
 * Total Accepted:    172.1K
 * Total Submissions: 421.9K
 * Testcase Example:  '1'
 *
 * 
 * Given an integer, write a function to determine if it is a power of two.
 * 
 */
bool isPowerOfTwo(int n)
{
    return n > 0 && !(n & n - 1);
}
