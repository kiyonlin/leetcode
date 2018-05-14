/*
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (34.65%)
 * Total Accepted:    77.4K
 * Total Submissions: 223.5K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2),
 * because they are adjacent houses.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 */
#define MAX(a, b) (a) > (b) ? (a) : (b)

int robSub(int* nums, int start, int end);

int rob(int* nums, int numsSize)
{
    // 首尾不能同时被抢，所以排除首和尾分别抢一边
    return numsSize == 1 ? nums[0] : MAX(robSub(nums, 0, numsSize - 1), robSub(nums, 1, numsSize));
}

int robSub(int* nums, int start, int end)
{
    int maxRob = 0, maxNotRob = 0,
        curRob, curNotRob;

    for (int i = start; i < end; i++) {
        curNotRob = maxRob;
        curRob = MAX(nums[i] + maxNotRob, curNotRob);
        maxRob = MAX(curRob, maxRob);
        maxNotRob = MAX(curNotRob, maxNotRob);
    }
    printf("[%d %d]", maxRob, maxNotRob);
    return MAX(maxRob, maxNotRob);
}
