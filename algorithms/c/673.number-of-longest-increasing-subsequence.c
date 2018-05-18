/*
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (31.76%)
 * Total Accepted:    15.7K
 * Total Submissions: 49.4K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 
 * Given an unsorted array of integers, find the number of longest increasing
 * subsequence.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1,
 * 3, 5, 7].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1,
 * and there are 5 subsequences' length is 1, so output 5.
 * 
 * 
 * 
 * Note:
 * Length of the given array will be not exceed 2000 and the answer is
 * guaranteed to be fit in 32-bit signed int.
 * 
 */
int findNumberOfLIS(int* nums, int numsSize)
{
    int* len = (int*)malloc(numsSize * sizeof(int));
    int* cnt = (int*)malloc(numsSize * sizeof(int));
    int result = 0, maxLen = 0;
    for (int i = 0; i < numsSize; i++) {
        len[i] = cnt[i] = 1;
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j]) {
                if (len[i] == len[j] + 1)
                    cnt[i] += cnt[j];
                if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }

        if (maxLen == len[i])
            result += cnt[i];
        if (maxLen < len[i]) {
            maxLen = len[i];
            result = cnt[i];
        }
    }
    return result;
}
