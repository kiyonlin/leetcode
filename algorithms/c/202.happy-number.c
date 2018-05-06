/*
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (41.71%)
 * Total Accepted:    162.1K
 * Total Submissions: 388.7K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 * 
 */
int squareSum(n)
{
    int r = 0;
    while (n) {
        int tmp = n % 10;
        r += tmp * tmp;
        n /= 10;
    }
    return r;
}
bool isHappy(int n)
{
    int slow, fast;
    slow = fast = n;
    do {
        // 使用链表环思路解决
        slow = squareSum(slow);
        fast = squareSum(fast);
        fast = squareSum(fast);
    } while (slow != fast);
    if (slow == 1)
        return true;
    return false;
}
