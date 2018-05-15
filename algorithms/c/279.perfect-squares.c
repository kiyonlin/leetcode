/*
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (37.79%)
 * Total Accepted:    111.2K
 * Total Submissions: 294.4K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 * 
 */
// 4平方定理
int numSquares(int n)
{
    int* dp = (int*)malloc(sizeof(int) * (n + 1));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int min = INT_MAX;
        for (int r = 1; r * r <= i; r++) {
            int t = dp[i - r * r] + 1;
            // printf("[r:%d,t:%d]", r, t);
            min = min < t ? min : t;
        }
        dp[i] = min;
    }
    return dp[n];
}
