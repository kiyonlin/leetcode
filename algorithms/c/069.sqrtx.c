/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (28.95%)
 * Total Accepted:    230.2K
 * Total Submissions: 795.2K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
int mySqrt(int x)
{
    if (x <= 1)
        return x;
    long result = 2;
    while (result * result <= x) {
        result++;
    }

    // 除法速度慢，但可以不考虑溢出
    // int result = 2;
    // while (result <= x / result) {
    //     result++;
    // }

    return result - 1;
}
