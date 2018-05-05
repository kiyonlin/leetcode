/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (48.14%)
 * Total Accepted:    260.9K
 * Total Submissions: 541.9K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
int majorityElement(int* nums, int numsSize)
{
    int major = nums[0], count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            count++;
            major = nums[i];
        } else if (major == nums[i]) {
            count++;
        } else {
            count--;
        }
    }
    return major;
}
