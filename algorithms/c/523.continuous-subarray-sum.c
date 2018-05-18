/*
 * [523] Continuous Subarray Sum
 *
 * https://leetcode.com/problems/continuous-subarray-sum/description/
 *
 * algorithms
 * Medium (23.39%)
 * Total Accepted:    34.4K
 * Total Submissions: 146.9K
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 * 
 * Given a list of non-negative numbers and a target integer k, write a
 * function to check if the array has a continuous subarray of size at least 2
 * that sums up to the multiple of k, that is, sums up to n*k where n is also
 * an integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [23, 2, 4, 6, 7],  k=6
 * Output: True
 * Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up
 * to 6.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [23, 2, 6, 4, 7],  k=6
 * Output: True
 * Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5
 * and sums up to 42.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array won't exceed 10,000.
 * You may assume the sum of all the numbers is in the range of a signed 32-bit
 * integer.
 * 
 * 
 */
bool checkSubarraySum(int* nums, int numsSize, int k)
{
    if (k < 0)
        k = -k;
    bool* dp = (bool*)calloc(k + 1, sizeof(bool));
    int sum = 0, k0 = 0;
    for (int i = 0; i < numsSize; i++) {
        sum = sum + nums[i];
        if (k != 0) {
            sum %= k;
            if (dp[sum]
                // for [1,1] 2
                || (i != 0 && sum == 0))
                return true;
            dp[sum] = true;
        } else {
            printf("[%d, %d, %d]", k0, dp[0], sum);
            if (k0 == 0 && dp[0] == sum)
                k0++;
            else if (k0 == 1 && dp[0] == sum)
                return true;
            else {
                dp[0] = sum;
                k0 = 0;
            }
        }
    }
    return false;
}
