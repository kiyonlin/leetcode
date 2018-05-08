/*
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (40.78%)
 * Total Accepted:    127.1K
 * Total Submissions: 311.7K
 * Testcase Example:  '27'
 *
 * 
 * ⁠   Given an integer, write a function to determine if it is a power of
 * three.
 * 
 * 
 * ⁠   Follow up:
 * ⁠   Could you do it without using any loop / recursion?
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
bool isPowerOfThree(int n)
{
    // int 范围内 3 的指数最大值为 pow(3,19) = 1162261467
    // 能整除 1162261467 的值都是3的指数
    return n > 0 && 1162261467 % n == 0;
}
