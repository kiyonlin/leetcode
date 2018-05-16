/*
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (38.93%)
 * Total Accepted:    43.8K
 * Total Submissions: 112.5K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * 
 * Note:
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 */
// 0-1背包问题
// 一维dp解法
bool canPartition(int* nums, int numsSize)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];
    if (sum & 1)
        return false;
    sum /= 2;

    bool* dp = (bool*)malloc(sizeof(bool*) * (sum + 1));
    dp[0] = true;
    for (int i = 0; i < numsSize; i++)
        for (int j = sum; j >= 1; j--)
            if (j >= nums[i])
                dp[j] = dp[j] || dp[j - nums[i]];

    return dp[sum];
}

// 二维dp解法
// bool canPartition(int* nums, int numsSize)
// {
//     int sum = 0;
//     for (int i = 0; i < numsSize; i++)
//         sum += nums[i];
//     if (sum & 1)
//         return false;
//     sum /= 2;

//     bool** dp = (bool**)malloc(sizeof(bool*) * (numsSize + 1));
//     for (int i = 0; i <= numsSize; i++) {
//         dp[i] = (bool*)calloc(sum + 1, sizeof(bool));
//         dp[i][0] = true;
//     }

//     for (int i = 1; i <= sum; i++)
//         dp[0][i] = false;

//     for (int i = 1; i <= numsSize; i++)
//         for (int j = 1; j <= sum; j++) {
//             dp[i][j] = dp[i - 1][j];
//             if (j >= nums[i - 1])
//                 dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
//         }
//     return dp[numsSize][sum];
// }
