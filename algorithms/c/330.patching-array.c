/*
 * [330] Patching Array
 *
 * https://leetcode.com/problems/patching-array/description/
 *
 * algorithms
 * Hard (32.72%)
 * Total Accepted:    26.5K
 * Total Submissions: 81.1K
 * Testcase Example:  '[1,3]\n6'
 *
 * Given a sorted positive integer array nums and an integer n, add/patch
 * elements to the array such that any number in range [1, n] inclusive can be
 * formed by the sum of some elements in the array. Return the minimum number
 * of patches required.
 * 
 * 
 * Example 1:
 * nums = [1, 3], n = 6
 * Return 1.
 * 
 * Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3,
 * 4.
 * Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3],
 * [2,3], [1,2,3].
 * Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
 * So we only need 1 patch.
 * 
 * Example 2:
 * nums = [1, 5, 10], n = 20
 * Return 2.
 * The two patches can be [2, 4].
 * 
 * Example 3:
 * nums = [1, 2, 2], n = 5
 * Return 0.
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
// [1...cover] + cover2 => [1...cover + cover2]
int minPatches(int* nums, int numsSize, int n)
{
    long cover = 1;
    int patchCount = 0, i = 0;
    while (cover <= n) {
        if (i < numsSize && cover >= nums[i]) {
            cover += nums[i++];
        } else {
            // patch this cover
            // printf("%ld ", cover);
            cover <<= 1;
            patchCount++;
        }
    }
    return patchCount;
}
