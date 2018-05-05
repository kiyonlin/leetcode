/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (40.28%)
 * Total Accepted:    171.4K
 * Total Submissions: 425.5K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes)
{
    // 分配二维数组的行数
    int** result = (int**)malloc(sizeof(int*) * numRows);
    // 分配一维数组的长度
    *columnSizes = (int*)malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++) {
        int* row = (int*)malloc(sizeof(int) * (i + 1));
        row[0] = row[i] = 1;
        for (int j = 1; j < i; j++) {
            row[j] = result[i - 1][j] + result[i - 1][j - 1];
        }
        result[i] = row;
        (*columnSizes)[i] = i + 1;
    }

    return result;
}
