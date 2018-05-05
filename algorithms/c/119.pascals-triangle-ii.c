/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (38.38%)
 * Total Accepted:    145.9K
 * Total Submissions: 380.1K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    *returnSize = rowIndex + 1;
    int* result = (int*)malloc(sizeof(int) * (rowIndex + 1));
    // 设置首位
    result[0] = 1;
    for (int i = 0; i <= rowIndex; i++) {
        // 设置新末位
        result[i] = 1;
        // 倒着遍历更新当前位置的值(加上前一个的值)
        for (int j = i - 1; j >= 1; j--) {
            result[j] += result[j - 1];
        }
    }
    return result;
}
