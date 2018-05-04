/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (40.35%)
 * Total Accepted:    309.5K
 * Total Submissions: 766.2K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
// 联机算法
// 当最大值小于0时，重新开始计算
int maxSubArray(int* nums, int numsSize)
{
    int maxSum = INT_MIN;
    int curSum = 0;
    for (int i = 0; i < numsSize; i++) {
        curSum += nums[i];
        if (curSum > maxSum) {
            maxSum = curSum;
        }
        if (curSum < 0) {
            curSum = 0;
        }
    }
    return maxSum;
}

// 分治算法
// inline int max3(int a, int b, int c)
// {
//     int max = a;
//     if (b > max)
//         max = b;
//     if (c > max)
//         max = c;
//     return max;
// }

// int maxSum(int* nums, int left, int right)
// {
//     if (left == right) {
//         return nums[left];
//     }
//     int i, middle = (left + right) / 2;

//     int leftBorder = 0, maxLeftBorder = INT_MIN;
//     for (i = middle; i >= left; i--) {
//         leftBorder += nums[i];
//         if (leftBorder > maxLeftBorder)
//             maxLeftBorder = leftBorder;
//     }

//     int rightBorder = 0, maxRightBorder = INT_MIN;
//     for (i = middle + 1; i <= right; i++) {
//         rightBorder += nums[i];
//         if (rightBorder > maxRightBorder)
//             maxRightBorder = rightBorder;
//     }
//     int maxLeft = maxSum(nums, left, middle);
//     int maxRight = maxSum(nums, middle + 1, right);
//     return max3(maxLeft, maxRight, maxLeftBorder + maxRightBorder);
// }

// int maxSubArray(int* nums, int numsSize)
// {
//     if (numsSize == 0)
//         return INT_MIN;
//     return maxSum(nums, 0, numsSize - 1);
// }