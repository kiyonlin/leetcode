/*
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (51.83%)
 * Total Accepted:    196.6K
 * Total Submissions: 379.2K
 * Testcase Example:  '0'
 *
 * 
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit. 
 * 
 * 
 * 
 * For example:
 * 
 * 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only
 * one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
// 参考：https://en.wikipedia.org/wiki/Digital_root
int addDigits(int num)
{
    return 1 + (num - 1) % 9;
}
