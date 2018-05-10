/*
 * [738] Monotone Increasing Digits
 *
 * https://leetcode.com/problems/monotone-increasing-digits/description/
 *
 * algorithms
 * Medium (41.06%)
 * Total Accepted:    6.2K
 * Total Submissions: 15.1K
 * Testcase Example:  '10'
 *
 * 
 * Given a non-negative integer N, find the largest number that is less than or
 * equal to N with monotone increasing digits.
 * 
 * (Recall that an integer has monotone increasing digits if and only if each
 * pair of adjacent digits x and y satisfy x .)
 * 
 * 
 * Example 1:
 * 
 * Input: N = 10
 * Output: 9
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: N = 1234
 * Output: 1234
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: N = 332
 * Output: 299
 * 
 * 
 * 
 * Note:
 * N is an integer in the range [0, 10^9].
 * 
 */
int monotoneIncreasingDigits(int N)
{
    int div = 10;
    while (N / div > 10)
        div *= 10;
    int pre = N / div, cur;
    int result = 0, count = 0;
    N %= div, div /= 10;
    while (div) {
        cur = N / div;
        result = result * 10 + pre;
        if (cur < pre) {
            // printf("%d %d %d", result, count, div);
            // handle 668841 -> 6688 1 10 -> 668000 - 1
            return result / (int)pow(10, count) * (int)pow(10, count + 1) * div - 1;
        }
        if (cur == pre)
            count++;
        if (cur > pre)
            // reset count
            count = 0;
        N %= div, div /= 10, pre = cur;
    }
    return result * 10 + cur;
}
