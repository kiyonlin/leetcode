/*
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (39.23%)
 * Total Accepted:    85.4K
 * Total Submissions: 217.6K
 * Testcase Example:  '16'
 *
 * 
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example:
 * Given num = 16, return true.
 * Given num = 5, return false.
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 * 
 * Credits:Special thanks to @yukuairoy  for adding this problem and creating
 * all test cases.
 */
bool isPowerOfFour(int num)
{
    // (n&(n-1)) 表示2的指数

    // 0x5 == (0101)B,  0x55555555 表示每个奇数位为1.
    // 4 == 100 奇数位为1
    // 16 == 10000 奇数位为1
    // 64 == 1000000 奇数位为1
    // (n & 0x55555555) 排除偶数位为1的结果
    return num > 0 && !(num & (num - 1)) && (num & 0x55555555);
}
