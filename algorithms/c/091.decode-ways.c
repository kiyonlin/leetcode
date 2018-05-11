/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (20.40%)
 * Total Accepted:    172.6K
 * Total Submissions: 845.8K
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
int numDecodings(char* s)
{
    int len = strlen(s);
    if (len < 2 && s[0] != '0')
        return len;
    int* dp = (int*)malloc(sizeof(int) * (len + 1));
    dp[0] = 1, dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 1; i < len; i++) {
        // s[i]不等于0时，s[i+1]可以直接解码，也就等于dp[i]
        dp[i + 1] = s[i] == '0' ? 0 : dp[i];
        // s[i]等于0时，且s[i-1]和s[i]可以组合解码，则等于dp[i-1]
        // 否则是无效编码（非1X或者20-26），无法解码
        dp[i + 1] += ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] < '7')) ? dp[i - 1] : 0;
    }
    return dp[len];
}
