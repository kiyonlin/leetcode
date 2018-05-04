/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (36.83%)
 * Total Accepted:    191.6K
 * Total Submissions: 519.6K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * 
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 * 
 * 
 */
char* countAndSay(int n)
{
    if (n < 2)
        return "1";
    char* cur = malloc(2);
    cur[0] = '1';
    cur[1] = '\0';
    for (int i = 2; i <= n; i++) {
        int len = strlen(cur);
        // 下一次say的字符串不会超过原字符串的两倍
        // 12321 -> 1112121211
        char* next = malloc(len * 2 + 1);
        char hold = cur[0];
        int count = 1, k = 0;
        for (int j = 1; j < len; j++) {
            if (cur[j] == hold) {
                count++;
            } else {
                next[k++] = '0' + count;
                next[k++] = hold;
                hold = cur[j];
                count = 1;
            }
        }
        next[k++] = '0' + count;
        next[k++] = hold;
        next[k] = '\0';
        free(cur);
        cur = next;
    }
    return cur;
}
