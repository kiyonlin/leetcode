/*
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (42.81%)
 * Total Accepted:    59.9K
 * Total Submissions: 139.8K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * ⁠Given an integer array with all positive numbers and no duplicates, find
 * the number of possible combinations that add up to a positive integer
 * target.
 * 
 * Example:
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * 
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers? 
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
int combinationSum4(int* nums, int numsSize, int target)
{
    // use calloc to avoid memory mix up
    int* dp = (int*)calloc(target + 1, sizeof(int));
    dp[0] = 1;
    for (int num = 1; num <= target; num++)
        for (int j = 0; j < numsSize; j++)
            if (nums[j] <= num)
                dp[num] += dp[num - nums[j]];

    return dp[target];
}
