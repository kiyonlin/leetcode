/*
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (62.34%)
 * Total Accepted:    112.6K
 * Total Submissions: 180.6K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * 
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 * 
 * 
 * Follow up:
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount  in c++ or in any other language.
 * 
 * 
 * 
 * Credits:Special thanks to @ syedee  for adding this problem and creating all
 * test cases.
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize)
{
    int* dp = (int*)malloc(sizeof(int) * (num + 1));
    for (dp[0] = 0, *returnSize = 1; *returnSize <= num; ++*returnSize)
        dp[*returnSize] = dp[*returnSize >> 1] + (*returnSize & 1);
    return dp;
}
