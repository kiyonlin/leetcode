/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (26.84%)
 * Total Accepted:    140.5K
 * Total Submissions: 523.4K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
#define MAX(a, b) (a) > (b) ? (a) : (b)

int maxProduct(int* nums, int numsSize)
{
    int result = INT_MIN;
    int front = 0, back = 0;
    for (int i = 0; i < numsSize; i++) {
        // 前后同时扫描，遇到0的时候 重置为0 继续向前
        front = front ? front *= nums[i] : nums[i];
        back = back ? back *= nums[numsSize - i - 1] : nums[numsSize - i - 1];
        // printf("[%d,%d]", front, back);
        result = MAX(result, MAX(front, back));
    }
    return result;
}
