/*
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (55.58%)
 * Total Accepted:    298.9K
 * Total Submissions: 537.8K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */
int singleNumber(int* nums, int numsSize)
{
    int target = nums[0];
    for (int i = 1; i < numsSize; i++) {
        target ^= nums[i];
    }
    return target;
}
