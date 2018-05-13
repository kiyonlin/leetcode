/*
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (35.15%)
 * Total Accepted:    133.7K
 * Total Submissions: 380.4K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
#define MIN(a, b) (a) < (b) ? (a) : (b)
int minimumTotal(int** triangle, int triangleRowSize, int* triangleColSizes)
{
    for (int i = 1; i < triangleRowSize; i++, *triangleColSizes++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else if (j == i)
                triangle[i][j] += triangle[i - 1][j - 1];
            else
                triangle[i][j] += MIN(triangle[i - 1][j], triangle[i - 1][j - 1]);
        }
    }
    int result = triangle[triangleRowSize - 1][0];
    for (int i = 1; i < *triangleColSizes; i++)
        result = MIN(result, triangle[triangleRowSize - 1][i]);
    return result;
}
