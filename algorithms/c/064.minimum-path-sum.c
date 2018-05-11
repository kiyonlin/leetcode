/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (41.12%)
 * Total Accepted:    150.8K
 * Total Submissions: 366.8K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
inline int min(int a, int b) { return a < b ? a : b; }

int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
    if (gridRowSize == 0 && gridColSize == 0)
        return 0;
    int** dp = (int**)malloc(sizeof(int*) * gridRowSize);
    for (int i = 0; i < gridRowSize; i++) {
        dp[i] = (int*)malloc(sizeof(int) * gridColSize);
        if (i == 0)
            dp[i][0] = grid[i][0];
        else
            dp[i][0] = grid[i][0] + dp[i - 1][0];
    }
    for (int i = 1; i < gridColSize; i++) {
        dp[0][i] = grid[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < gridRowSize; i++) {
        for (int j = 1; j < gridColSize; j++) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[gridRowSize - 1][gridColSize - 1];
}
