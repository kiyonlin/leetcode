/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (38.95%)
 * Total Accepted:    127.3K
 * Total Submissions: 326.8K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * 
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length
 * is 4. Note that there may be more than one LIS combination, it is only
 * necessary for you to return the length.
 * 
 * 
 * Your algorithm should run in O(n2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity? 
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
// find the first pos of the number which larger than target
int firstLarge(int* nums, int size, int target);

int lengthOfLIS(int* nums, int numsSize)
{
    if (!numsSize)
        return 0;
    // 构造当前最优的递增子序列
    int* hold = (int*)malloc(sizeof(int) * numsSize);
    int max = 1;
    hold[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > hold[max - 1])
            hold[max++] = nums[i];
        else {
            int pos = firstLarge(hold, max, nums[i]);
            hold[pos] = nums[i];
        }
    }

    return max;
}

int firstLarge(int* nums, int size, int target)
{
    int left = 0, right = size - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
