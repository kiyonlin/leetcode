/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.71%)
 * Total Accepted:    478K
 * Total Submissions: 1.9M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
// Hash法 983/983 cases passed (28 ms)
int lengthOfLongestSubstring(char* s)
{
    int len = strlen(s);
    if (len == 0 || len == 1)
        return len;
    int maxLength = 1, i, j;
    int hit[256] = { 0 };
    for (i = 0; i < len; i++) {
        hit[s[i]] = 1;
        for (j = i + 1; j < len; j++) {
            if (hit[s[j]] == 0) {
                hit[s[j]] = 1;
            } else {
                if (j - i > maxLength) {
                    maxLength = j - i;
                }
                break;
            }
        }
        if (j - i > maxLength) {
            maxLength = j - i;
        }
        // 清除标记
        for (int k = i; k <= j; k++)
            hit[s[k]] = 0;
    }
    return maxLength;
}
