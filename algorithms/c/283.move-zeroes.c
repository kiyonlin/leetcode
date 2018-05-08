/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (51.64%)
 * Total Accepted:    289K
 * Total Submissions: 559.7K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * 
 * 
 * For example, given nums  = [0, 1, 0, 3, 12], after calling your function,
 * nums should be [1, 3, 12, 0, 0].
 * 
 * 
 * 
 * Note:
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
inline void swap(int* a, int* b)
{
    if (*a == *b)
        return;
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void moveZeroes(int* nums, int numsSize)
{
    for (int i = 0, j = 0; i < numsSize; i++) {
        if (nums[i]) {
            swap(&nums[i], &nums[j++]);
        }
    }
}
