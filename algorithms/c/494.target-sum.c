/*
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (43.84%)
 * Total Accepted:    52.8K
 * Total Submissions: 120.5K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
// 求解 nums 中子集的和等于 P 的方案个数
// https://blog.csdn.net/mine_song/article/details/70216562
int findTargetSumWays(int* nums, int numsSize, int S)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
        sum += nums[i];

    // 数组的和小于S(正数)或者大于S(负数)或者两者之和不为偶数，直接返回0
    if (sum < S || -sum > S || (sum + S) & 1 == 1)
        return 0;

    sum = (sum + S) / 2;
    int* dp = (int*)calloc(sum + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++)
        for (int j = sum; j >= nums[i]; j--)
            dp[j] += dp[j - nums[i]];

    return dp[sum];
}
