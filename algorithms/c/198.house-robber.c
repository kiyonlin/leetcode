/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (40.03%)
 * Total Accepted:    201.2K
 * Total Submissions: 502.7K
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 */
inline max(int a, int b) { return a > b ? a : b; }

int rob(int* nums, int numsSize)
{
    int maxRob = 0;
    int maxNotRob = 0;
    for (int i = 0; i < numsSize; i++) {
        // 抢了i，加上之间没抢的最大值
        int curRob = nums[i] + maxNotRob;
        // 不抢i，最大值为上一次抢的值
        int curNotRob = maxRob;
        maxRob = max(maxRob, curRob);
        maxNotRob = max(maxNotRob, curNotRob);
    }
    return max(maxRob, maxNotRob);
}
