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
    //Based on Lagrange's Four Square theorem, there
    //are only 4 possible results: 1, 2, 3, 4.
    //The result is 4 if and only if n can be written in the form of 4^k*(8*m + 7).
    while (n % 4 == 0)
        n >>= 2;
    if (n % 8 == 7)
        return 4;
    for (int a = 0; a * a <= n; ++a) //consider 1 and 2;
    {
        int b = sqrt(n - a * a);
        // printf("[%d %d]", a, b);
        if (a * a + b * b == n)
            return 1 + !!a; //if a==0, then return 1 otherwise return 2;
    }
    return 3;
}

// int numSquares(int n)
// {
//     int* dp = (int*)malloc(sizeof(int) * (n + 1));
//     dp[0] = 0;
//     for (int i = 1; i <= n; i++) {
//         int min = INT_MAX;
//         for (int r = 1; r * r <= i; r++) {
//             int t = dp[i - r * r] + 1;
//             // printf("[r:%d,t:%d]", r, t);
//             min = min < t ? min : t;
//         }
//         dp[i] = min;
//     }
//     return dp[n];
// }
