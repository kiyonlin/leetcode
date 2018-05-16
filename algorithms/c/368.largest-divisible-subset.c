/*
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (33.95%)
 * Total Accepted:    34.5K
 * Total Submissions: 101.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj
 * % Si = 0.
 * 
 * 
 * If there are multiple solutions, return any subset is fine.
 * 
 * 
 * Example 1:
 * 
 * nums: [1,2,3]
 * 
 * Result: [1,2] (of course, [1,3] will also be ok)
 * 
 * 
 * 
 * Example 2:
 * 
 * nums: [1,2,4,8]
 * 
 * Result: [1,2,4,8]
 * 
 * 
 * 
 * Credits:Special thanks to @Stomach_ache for adding this problem and creating
 * all test cases.
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int asc(void* a, void* b) { return *(int*)a - *(int*)b; }

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize)
{
    if (numsSize == 0)
        return NULL;
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int* link = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++)
        dp[i] = 1, link[i] = i;
    qsort(nums, numsSize, sizeof(int), asc);
    int tail = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++)
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1, link[i] = j;

        if (dp[i] > *returnSize)
            // 记录最大长度和下标尾
            *returnSize = dp[i], tail = i;
    }

    // 回溯获取结果
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    int k = 0;
    while (link[tail] != tail) {
        result[k++] = nums[tail];
        tail = link[tail];
    }
    result[k] = nums[tail];
    free(dp), free(link);
    return result;
}
