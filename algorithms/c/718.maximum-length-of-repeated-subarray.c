/*
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (41.57%)
 * Total Accepted:    13.8K
 * Total Submissions: 33.1K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * Given two integer arrays A and B, return the maximum length of an subarray
 * that appears in both arrays.
 * 
 * Example 1:
 * 
 * Input:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * Output: 3
 * Explanation: 
 * The repeated subarray with maximum length is [3, 2, 1].
 * 
 * 
 * 
 * Note:
 * 
 * 1 
 * 0 
 * 
 * 
 */
inline int MAX(int a, int b) { return a > b ? a : b; }
int findLength(int* A, int ASize, int* B, int BSize)
{
    int dp[ASize + 1][BSize + 1];
    memset(dp, 0, sizeof(dp));
    int result = 0;
    for (int i = 0; i < ASize; i++)
        for (int j = 0; j < BSize; j++)
            if (A[i] == B[j])
                dp[i + 1][j + 1] = dp[i][j] + 1, result = MAX(result, dp[i + 1][j + 1]);
    return result;
}
