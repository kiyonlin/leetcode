/*
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (46.16%)
 * Total Accepted:    47.6K
 * Total Submissions: 103.2K
 * Testcase Example:  '2'
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10n.
 * 
 * 
 * ⁠   Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the range
 * of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 * 
 * 
 * Credits:Special thanks to @memoryless for adding this problem and creating
 * all test cases.
 */
int countNumbersWithUniqueDigits(int n)
{
    // combination
    // 1:10
    // 2:10 + 9*9
    // 3:10 + 9*9*8
    // ...
    if (n == 0)
        return 1;
    int cmn = 9, count = 9, result = 10;
    while (n-- > 1) {
        cmn = cmn * count--;
        result += cmn;
    }
    return result;
}
