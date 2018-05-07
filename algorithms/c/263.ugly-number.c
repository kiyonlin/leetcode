/*
 * [263] Ugly Number
 *
 * https://leetcode.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (39.72%)
 * Total Accepted:    123.4K
 * Total Submissions: 310.6K
 * Testcase Example:  '6'
 *
 * Write a program to check whether a given number is an ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 6, 8 are ugly while 14 is not ugly since it includes another
 * prime factor 7.
 * 
 * Note:
 * 
 * 
 * 1 is typically treated as an ugly number.
 * Input is within the 32-bit signed integer range.
 * 
 * 
 * 
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating
 * all test cases.
 * 
 */
bool isUgly(int num)
{
    if (num <= 0)
        return false;
    while (num > 1) {
        if (num % 2 == 0)
            num /= 2;
        else if (num % 3 == 0)
            num /= 3;
        else if (num % 5 == 0)
            num /= 5;
        else
            return false;
    }
    return true;
}
