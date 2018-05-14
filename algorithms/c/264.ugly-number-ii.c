/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (33.40%)
 * Total Accepted:    75.5K
 * Total Submissions: 226K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 * 
 */
inline int MIN(int a, int b) { return a < b ? a : b; }

int nthUglyNumber(int n)
{
    int* dp = (int*)malloc(sizeof(int) * n);
    dp[0] = 1;
    int c2 = 0, c3 = 0, c5 = 0;
    for (int c = 1; c < n; c++) {
        // printf("[%d,%d,%d]", dp[c2], dp[c3], dp[c5]);
        dp[c] = MIN(MIN(2 * dp[c2], 3 * dp[c3]), 5 * dp[c5]);
        if (dp[c] == 2 * dp[c2])
            c2++;
        if (dp[c] == 3 * dp[c3])
            c3++;
        if (dp[c] == 5 * dp[c5])
            c5++;
    }
    return dp[n - 1];
}
