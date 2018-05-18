/*
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (42.90%)
 * Total Accepted:    31.6K
 * Total Submissions: 73.5K
 * Testcase Example:  '"bbbab"'
 *
 * 
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * 
 * Example 1:
 * Input: 
 * 
 * "bbbab"
 * 
 * Output: 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * Example 2:
 * Input:
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 */
inline int MAX(int a, int b) { return a > b ? a : b; }

int longestPalindromeSubseq(char* s)
{
    int len = strlen(s);
    if (len == 0)
        return 0;
    int** dp = (int**)malloc(len * sizeof(int*));
    for (int i = 0; i < len; i++)
        dp[i] = (int*)malloc(len * sizeof(int));

    for (int i = len - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = MAX(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][len - 1];
}
