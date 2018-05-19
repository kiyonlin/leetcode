/*
 * [712] Minimum ASCII Delete Sum for Two Strings
 *
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (51.58%)
 * Total Accepted:    8.2K
 * Total Submissions: 16K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters to
 * make two strings equal.
 * 
 * Example 1:
 * 
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to
 * the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum
 * possible to achieve this.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e]
 * to the sum.
 * At the end, both strings are equal to "let", and the answer is
 * 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers
 * of 433 or 417, which are higher.
 * 
 * 
 * 
 * Note:
 * 0 < s1.length, s2.length .
 * All elements of each string will have an ASCII value in [97, 122]. 
 * 
 */
inline int MIN(int a, int b) { return a < b ? a : b; }

int minimumDeleteSum(char* s1, char* s2)
{
    int l1 = strlen(s1), l2 = strlen(s2);
    int dp[l1 + 1][l2 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = l1 - 1; i >= 0; i--)
        dp[i][l2] = dp[i + 1][l2] + s1[i];
    for (int i = l2 - 1; i >= 0; i--)
        dp[l1][i] = dp[l1][i + 1] + s2[i];
    for (int i = l1 - 1; i >= 0; i--)
        for (int j = l2 - 1; j >= 0; j--)
            if (s1[i] == s2[j])
                dp[i][j] = dp[i + 1][j + 1];
            else
                dp[i][j] = MIN(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);
    return dp[0][0];
}
