/*
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.09%)
 * Total Accepted:    35.9K
 * Total Submissions: 119.3K
 * Testcase Example:  '3'
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 231).
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 * 
 * 
 */
int findNthDigit(int n)
{
    long t[10] = { 0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889 };
    for (int i = 1; i <= 9; i++) {
        if (n <= t[i]) {
            int num = (int)pow(10, i - 1) + (n - t[i - 1] - 1) / i;
            int rest = i - 1 - (n - t[i - 1] - 1) % i;
            int div = pow(10, rest);
            // printf("%d, %d", num, rest);
            return num / div % 10;
        }
    }
    return 0;
}
