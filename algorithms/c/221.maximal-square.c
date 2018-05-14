/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (30.48%)
 * Total Accepted:    88.5K
 * Total Submissions: 290.4K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 * 
 */
inline int MAX(int a, int b) { return a > b ? a : b; }
inline int MIN(int a, int b) { return a < b ? a : b; }

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize)
{
    if (!(matrixRowSize && matrixColSize))
        return 0;
    int maxWidth = 0;
    int** square = (int**)malloc(sizeof(int*) * (matrixRowSize + 1));
    for (int i = 0; i <= matrixRowSize; i++)
        square[i] = (int*)calloc(matrixColSize + 1, sizeof(int));

    for (int i = 1; i <= matrixRowSize; i++)
        for (int j = 1; j <= matrixColSize; j++) {
            if (matrix[i - 1][j - 1] == '1')
                square[i][j] = MIN(MIN(square[i - 1][j], square[i][j - 1]), square[i - 1][j - 1]) + 1;
            maxWidth = MAX(maxWidth, square[i][j]);
        }

    return maxWidth * maxWidth;
}
