/*
 * [467] Unique Substrings in Wraparound String
 *
 * https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/
 *
 * algorithms
 * Medium (33.32%)
 * Total Accepted:    12.8K
 * Total Submissions: 38.4K
 * Testcase Example:  '"a"'
 *
 * Consider the string s to be the infinite wraparound string of
 * "abcdefghijklmnopqrstuvwxyz", so s will look like this:
 * "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
 * 
 * Now we have another string p. Your job is to find out how many unique
 * non-empty substrings of p are present in s. In particular, your input is the
 * string p and you need to output the number of different non-empty substrings
 * of p in the string s.
 * 
 * Note: p consists of only lowercase English letters and the size of p might
 * be over 10000.
 * 
 * Example 1:
 * 
 * Input: "a"
 * Output: 1
 * 
 * Explanation: Only the substring "a" of string "a" is in the string s.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "cac"
 * Output: 2
 * Explanation: There are two substrings "a", "c" of string "cac" in the string
 * s.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "zab"
 * Output: 6
 * Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of
 * string "zab" in the string s.
 * 
 * 
 */
inline int MAX(int a, int b) { return a > b ? a : b; }

int findSubstringInWraproundString(char* p)
{
    if (!*p)
        return 0;
    int dp[26] = { 0 }, len = 1;

    dp[p[0] - 'a'] = 1;
    for (int i = 1; p[i] != '\0'; i++) {
        len = (p[i] - p[i - 1] == 1 || p[i] - p[i - 1] == -25) ? len + 1 : 1;
        dp[p[i] - 'a'] = MAX(dp[p[i] - 'a'], len);
    }
    int result = 0;
    for (int i = 0; i < 26; i++)
        result += dp[i];

    return result;
}
