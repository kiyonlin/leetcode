/*
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (32.24%)
 * Total Accepted:    136.5K
 * Total Submissions: 423.4K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
    if (obstacleGridRowSize == 0 && obstacleGridColSize == 0)
        return 0;
    int** dp = (int**)malloc(sizeof(int*) * obstacleGridRowSize);
    for (int i = 0; i < obstacleGridRowSize; i++)
        dp[i] = (int*)calloc(obstacleGridColSize, sizeof(int));

    for (int i = 0; i < obstacleGridColSize; i++) {
        if (obstacleGrid[0][i] == 0)
            dp[0][i] = 1;
        else
            break;
    }
    for (int i = 0; i < obstacleGridRowSize; i++) {
        if (obstacleGrid[i][0] == 0)
            dp[i][0] = 1;
        else
            break;
    }
    for (int i = 1; i < obstacleGridRowSize; i++) {
        for (int j = 1; j < obstacleGridColSize; j++) {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[obstacleGridRowSize - 1][obstacleGridColSize - 1];
}
