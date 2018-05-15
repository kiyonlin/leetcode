/*
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (27.48%)
 * Total Accepted:    44.6K
 * Total Submissions: 162.1K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 * 
 * 
 * 
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 * 
 * 
 * Example:
 * 
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 * 
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 * 
 * 
 */
typedef struct {
    int** dp;
    int row;
    int col;
} NumMatrix;

int V(int** dp, int i, int j) { return i >= 0 && j >= 0 ? dp[i][j] : 0; }

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize)
{
    NumMatrix* nm = (NumMatrix*)malloc(sizeof(NumMatrix));
    nm->row = matrixRowSize;
    nm->col = matrixColSize;
    nm->dp = (int**)malloc(sizeof(int*) * matrixRowSize);
    for (int i = 0; i < matrixRowSize; i++)
        nm->dp[i] = (int*)malloc(sizeof(int) * matrixColSize);

    for (int i = 0; i < matrixRowSize; i++)
        for (int j = 0; j < matrixColSize; j++)
            nm->dp[i][j] = matrix[i][j] + V(nm->dp, i - 1, j) + V(nm->dp, i, j - 1) - V(nm->dp, i - 1, j - 1);
    return nm;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2)
{
    return V(obj->dp, row2, col2)
        - V(obj->dp, row1 - 1, col2)
        - V(obj->dp, row2, col1 - 1)
        + V(obj->dp, row1 - 1, col1 - 1);
}

void numMatrixFree(NumMatrix* obj)
{
    for (int i = 0; i < obj->row; i++)
        free(obj->dp[i]);
    free(obj->dp);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * struct NumMatrix* obj = numMatrixCreate(matrix, matrixRowSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 * numMatrixFree(obj);
 */
