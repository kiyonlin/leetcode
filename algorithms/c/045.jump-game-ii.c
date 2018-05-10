/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (26.09%)
 * Total Accepted:    116.3K
 * Total Submissions: 445.8K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 */

int jump(int* nums, int numsSize)
{
    // now:当前下标 last:前一步最大下标， step 已经跳的步数
    int now = 0, last = 0, step = 0;
    for (int i = 0; now < numsSize - 1; i++) {
        if (nums[i] + i > now)
            now = nums[i] + i;
        if (i == last)
            // 接着前一步跳
            ++step, last = now;
        printf("%d %d %d-->", now, last, step);
    }
    return now > last ? step + 1 : step;
}
