/*
 * [576] Out of Boundary Paths
 *
 * https://leetcode.com/problems/out-of-boundary-paths/description/
 *
 * algorithms
 * Medium (30.49%)
 * Total Accepted:    10K
 * Total Submissions: 32.9K
 * Testcase Example:  '2\n2\n2\n0\n0'
 *
 * There is an m by n grid with a ball. Given the start coordinate (i,j) of the
 * ball, you can move the ball to adjacent cell or cross the grid boundary in
 * four directions (up, down, left, right). However, you can at most move N
 * times. Find out the number of paths to move the ball out of grid boundary.
 * The answer may be very large, return it after mod 109 + 7.
 * 
 * Example 1:
 * 
 * Input:m = 2, n = 2, N = 2, i = 0, j = 0
 * Output: 6
 * Explanation:
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:m = 1, n = 3, N = 3, i = 0, j = 1
 * Output: 12
 * Explanation:
 * 
 * 
 * 
 * 
 * Note:
 * 
 * Once you move the ball out of boundary, you cannot move it back.
 * The length and height of the grid is in range [1,50].
 * N is in range [0,50].
 * 
 * 
 */

int** init(int m, int n)
{
    int** a = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        a[i] = (int*)calloc(n, sizeof(int));
    return a;
}

int v(int** a, int m, int n, int i, int j) { return (i < 0 || i == m || j < 0 || j == n) ? 0 : a[i][j]; }

void freeTemp(int** a, int m)
{
    for (int i = 0; i < m; i++)
        free(a[i]);
    free(a);
}
// 迭代法
int findPaths(int m, int n, int N, int x, int y)
{
    int M = 1000000007;
    int** dp = init(m, n);
    dp[x][y] = 1;
    int count = 0;
    for (int moves = 1; moves <= N; moves++) {
        int** temp = init(m, n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i == 0)
                    count = (count + dp[i][j]) % M;
                if (i == m - 1)
                    count = (count + dp[i][j]) % M;
                if (j == 0)
                    count = (count + dp[i][j]) % M;
                if (j == n - 1)
                    count = (count + dp[i][j]) % M;

                temp[i][j] = ((v(dp, m, n, i - 1, j) + v(dp, m, n, i + 1, j)) % M
                                 + (v(dp, m, n, i, j - 1) + v(dp, m, n, i, j + 1)) % M)
                    % M;
            }
        freeTemp(dp, m);
        dp = temp;
    }
    return count;
}

// 递归法
// int M = 1000000007;
//
// int go(int m, int n, int N, int i, int j, int*** dp)
// {
//     if (i == -1 || j == -1 || i == m || j == n) {
//         return 1;
//     }
//     if (N == 0)
//         return 0;
//     if (dp[i][j][N] == -1) {
//         dp[i][j][N] = ((go(m, n, N - 1, i + 1, j, dp) + go(m, n, N - 1, i - 1, j, dp)) % M
//                           + (go(m, n, N - 1, i, j - 1, dp) + go(m, n, N - 1, i, j + 1, dp)) % M)
//             % M;
//     }
//     return dp[i][j][N];
// }
// int*** init(int m, int n, int N)
// {
//     int*** dp = (int***)malloc(m * sizeof(int**));
//     for (int i = 0; i < m; i++) {
//         dp[i] = (int**)malloc(n * sizeof(int*));
//         for (int j = 0; j < n; j++) {
//             dp[i][j] = (int*)malloc((N + 1) * sizeof(int));
//             memset(dp[i][j], -1, sizeof(int) * (N + 1));
//         }
//     }
//     return dp;
// }
// int findPaths(int m, int n, int N, int i, int j)
// {
//     return go(m, n, N, i, j, init(m, n, N));
// }
