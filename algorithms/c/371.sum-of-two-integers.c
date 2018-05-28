/*
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.84%)
 * Total Accepted:    98.9K
 * Total Submissions: 194.5K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * Example:
 * Given a = 1 and b = 2, return 3.
 * 
 * 
 * Credits:Special thanks to @fujiaozhu for adding this problem and creating
 * all test cases.
 */
int getSum(int a, int b)
{
    int sum = a, carry = b;
    while (carry) {
        int temp = sum;
        // 半加器
        sum ^= carry;
        // 进位
        carry = (temp & carry) << 1;
    }
    return sum;
}
