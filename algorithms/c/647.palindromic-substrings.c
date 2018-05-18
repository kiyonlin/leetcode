/*
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (54.65%)
 * Total Accepted:    41.6K
 * Total Submissions: 76.3K
 * Testcase Example:  '"abc"'
 *
 * 
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * 
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters. 
 * 
 * 
 * Example 1:
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Note:
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 */
int isPal(char*, int, int, int);

int countSubstrings(char* s)
{
    int len = strlen(s);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        cnt += isPal(s, i, i, len);
        cnt += isPal(s, i, i + 1, len);
    }
    return cnt;
}

int isPal(char* s, int i, int j, int len)
{
    int cnt = 0;
    while (i >= 0 && j < len && s[i--] == s[j++])
        cnt++;
    return cnt;
}
